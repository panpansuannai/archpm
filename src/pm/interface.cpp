/*
 *  interface.cpp
 *
 *  Copyright (c) 2020 panpansuannai <panpansuannai@outlook.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "interface.h"
#include "conf.h"
#include "debug.h"
#include "util.h"

#include <cstring>
#include <fstream>
#include <queue>
#include <sys/wait.h>

#define TAR_LEN 512
#define FILE_LEN 1024
#define CONTENT_SIZE 2048

#ifndef SEARCH_LOCAL_WITH_HASH
#define SEARCH_LOCAL_WITH_HASH

#endif // SEARCH_LOCAL_WITH_HASH

operation::operation() {
  this->conf = new conf_t();
  alpm_db_t *localdb = alpm_get_localdb(conf->handle);
  alpm_list_t *pkgs = alpm_db_get_pkgcache(localdb);
  alpm_list_t *i;
  /* init hash table */
  for (i = pkgs; i; i = alpm_list_next(i)) {
    hash_add(hash_compute((alpm_pkg_t *)i->data));
  }
  /* init Trie */
  trie_init();
}
/*-----------------------------PKG SEARCH-----------------------------*/

/* calculate the "next" for the KMP */
static void calc_next(int *next, int len, const char *text) {
  next[0] = 0;
  int f = 0, b = 1;
  while (b < len) {
    if (text[f] == text[b]) {
      next[b] = f + 1;
      f++;
      b++;
    } else {
      if (f == 0) {
        next[b] = 0;
        b++;
      } else
        f = next[f - 1];
    }
  }
}

/* @brief compare two strings with KMP
 * @param patten the patten string
 * @param s the target
 * @param next array calculate by calc_next function
 * @param plen the length of the patten string
 */
static bool KMP_cmp(const char *patten, const char *s, int *next, int plen) {
  int len = strlen(s);
  int v = 0;
  for (int i = 0; i < len && v < plen; ++i) {
    if (patten[v] != s[i]) {
      v = next[v];
    } else {
      v++;
    }
    if (v == plen) {
      return true;
    }
  }
  return false;
}

/* @brief search the local database for the packages whose name or description
 *      contain the patten string
 * @param text the patten string
 * @param sdb which database to search
 */
alpm_list_t *operation::get_pkgs_by_KMP(const char *text, int sdb) {
  alpm_list_t *ret = nullptr;
  alpm_list_t *dbs = nullptr;
  int length = strlen(text);
  int next[length];
  memset(next, 0, sizeof(int) * length);

  calc_next(next, length, text);

  dbs = alpm_list_add(dbs, alpm_get_localdb(conf->handle));
  dbs = alpm_list_join(dbs, alpm_get_syncdbs(conf->handle));

  alpm_list_t *k;
  for (k = dbs; k; k = alpm_list_next(k)) {
    alpm_db_t *db = (alpm_db_t *)k->data;
    pkg_hash h = hash_compute(alpm_db_get_name(db));
    if (match_db(db, sdb)) {
      sdb &= ~match_db(db, sdb);
      alpm_list_t *pkgs = alpm_db_get_pkgcache(db);
      alpm_list_t *i;
      for (i = pkgs; i; i = alpm_list_next(i)) {
        const char *name = (char *)alpm_pkg_get_name((alpm_pkg_t *)i->data);
        const char *desc = (char *)alpm_pkg_get_desc((alpm_pkg_t *)i->data);
        if (KMP_cmp(text, name, next, length) ||
            KMP_cmp(text, desc, next, length)) {
          ret = alpm_list_add(ret, (alpm_pkg_t *)i->data);
        }
      }
    }
  }
  return ret;
}

/* @brief search the database for packages whose name contain the
 *      @text
 */
alpm_list_t *operation::get_pkgs_by_Trie(const char *text, int sdb) {
  alpm_list_t *ret = nullptr;
  alpm_list_t *dbs = alpm_list_add(nullptr, alpm_get_localdb(conf->handle));
  dbs = alpm_list_join(dbs, alpm_get_syncdbs(conf->handle));
  alpm_list_t *i;
  for (i = dbs; i; i = alpm_list_next(i)) {
    alpm_db_t *db = (alpm_db_t *)i->data;
    if (match_db(db, sdb & CORE)) {
      sdb &= ~CORE;
      ret = alpm_list_join(ret, trie_clt(Trie->core, text));
    } else if (match_db(db, sdb & COMMUNITY)) {
      sdb &= ~COMMUNITY;
      ret = alpm_list_join(ret, trie_clt(Trie->community, text));
    } else if (match_db(db, sdb & EXTRA)) {
      sdb &= ~EXTRA;
      ret = alpm_list_join(ret, trie_clt(Trie->extra, text));
    } else if (match_db(db, sdb & LOCAL)) {
      sdb &= ~LOCAL;
      ret = alpm_list_join(ret, trie_clt(Trie->local, text));
    }
  }
  return ret;
}
/* @brief search the local database to get a packages
 *      whose name is @name
 */
alpm_pkg_t *operation::get_localpkg(const char *name) {
  pkg_hash tar_hash = hash_compute(name);
  alpm_list_t *pkgcache = alpm_db_get_pkgcache(alpm_get_localdb(conf->handle));
  alpm_list_t *i;
  for (i = pkgcache; i; i = alpm_list_next(i)) {
    alpm_pkg_t *pkg = (alpm_pkg_t *)i->data;
    if (hash_compute(pkg) == tar_hash) {
      return pkg;
    }
  }
  return nullptr;
}
/* @brief search the list of database to get packages whose name is @name
 * @param dbs a list of database
 * @parma name the name of packages
 */
alpm_pkg_t *operation::find_dbs_pkg(alpm_list_t *dbs, const char *name) {
  alpm_pkg_t *ret = nullptr;
  if (!name)
    return ret;
  alpm_list_t *databases = dbs;
  alpm_list_t *i;
  for (i = dbs; i; i = alpm_list_next(i)) {
    alpm_db_t *db = (alpm_db_t *)i->data;
    ret = alpm_db_get_pkg(db, name);
    if (ret)
      return ret;
  }
  return ret;
}

/* search pkgs by regular expression */
alpm_list_t *operation::get_pkgs_by_regex(const char *pkgname, int sdb) {
  if (pkgname == nullptr) {
    return nullptr;
  }
  alpm_list_t *regex = str_split(pkgname);
  alpm_db_t *db;
  alpm_list_t *retpkgs = nullptr, *partpkgs = nullptr;

  alpm_list_t *dbs = alpm_get_syncdbs(conf->handle);
  dbs = alpm_list_add(dbs, alpm_get_localdb(conf->handle));
  alpm_list_t *i;
  for (i = dbs; i; i = alpm_list_next(i)) {
    db = (alpm_db_t *)i->data;
    if (match_db(db, sdb)) {
      sdb &= ~match_db(db, sdb);
      partpkgs = alpm_db_search(db, regex);
      if (partpkgs) {
        retpkgs = alpm_list_join(retpkgs, partpkgs);
      }
    }
  }
  /* free memory */
  FREELIST(regex);
  return retpkgs;
}
/*----------------------------INSTALL&REMOVE-----------------------*/

bool operation::find_chars_pkg(alpm_list_t *list, alpm_pkg_t *pkg) {
  alpm_list_t *i;
  for (i = list; i; i = alpm_list_next(i)) {
    const char *c = (char *)i->data;
    pkg_hash h = hash_compute(pkg);
    if (hash_compute(c) == h) {
      return true;
    }
  }
  return false;
}
/* @brief check the configure before operate on
 *   a package
 * @param pkg which package to operate
 * @param flag which operation to do
 * @return the result
 */
int operation::to_change_pkg(alpm_pkg_t *pkg, int flag) {
  if (flag & PKG_UPGRADE) {
    if (find_chars_pkg(conf->noupgrades, pkg))
      return PKG_UPGRADE;
  }
  if (flag & PKG_INSTALL) {
    if (find_chars_pkg(conf->holdpkgs, pkg) ||
        find_chars_pkg(conf->ignorepkgs, pkg))
      return PKG_INSTALL;
  }
  if (flag & PKG_REMOVE) {
    if (find_chars_pkg(conf->holdpkgs, pkg) ||
        find_chars_pkg(conf->ignorepkgs, pkg))
      return PKG_REMOVE;
  }
  return PKG_OK;
}

/* @brief return a list of packages which had
 * been installed
 */
alpm_list_t *operation::get_installed_pkgs() {
  alpm_db_t *localdb = alpm_get_localdb(conf->handle);
  return alpm_db_get_pkgcache(localdb);
}

/* @brief install a package and then update the Trie
 *  and hash table
 * @param pkg the target package
 */
int operation::install(alpm_pkg_t *pkg) {
  alpm_list_t *data = nullptr;
  int ret;
  ret = alpm_trans_init(conf->handle, 1);
  if (ret) {
    alpm_trans_release(conf->handle);
    return 1;
  }
  ret = alpm_add_pkg(conf->handle, pkg);
  if (ret) {
    alpm_trans_release(conf->handle);
    return 1;
  }
  ret = alpm_trans_prepare(conf->handle, &data);
  if (ret) {
    alpm_trans_release(conf->handle);
    return 1;
  }
  ret = alpm_trans_commit(conf->handle, &data);
  if (ret) {
    alpm_trans_release(conf->handle);
    return 1;
  }
  alpm_trans_release(conf->handle);

  hash_add(hash_compute(pkg));
  alpm_pkg_t *p = get_localpkg(alpm_pkg_get_name(pkg));
  if (p) {
    trie_add(Trie->local, p);
  }
  return 0;
}
/* @brief call the command line tools--pacman to do the
 *   install things
 * @param pkgs a list of packages wanted to be installed
 * @return 0 if succeed 1 if not
 */
int operation::install_list(alpm_list_t *pkgs) {
#ifdef INSTALL_WITH_PACMAN
  char *args[TAR_LEN];
  memset(args, 0, TAR_LEN * sizeof(char *));

  int index = 0;
  args[index++] = strdup("pacman");
  args[index++] = strdup("--noconfirm");
  /* setup cache directory */
  alpm_list_t *i, *cachedirs = alpm_option_get_cachedirs(conf->handle);
  if (cachedirs) {
    args[index++] = strdup("--cachedir");
    for (i = cachedirs; i; i = alpm_list_next(i)) {
      args[index++] = strdup((char *)i->data);
    }
  }

  args[index++] = strdup("-Sddq");
  alpm_pkg_t *p;
  for (i = pkgs; i; i = alpm_list_next(i)) {
    p = (alpm_pkg_t *)i->data;
    args[index++] = strdup(alpm_pkg_get_name(p));
    hash_add(hash_compute(p));
  }
  args[index] = NULL;
  int pid = fork();
  if (pid == 0) {
    execv("/usr/bin/pacman", args);
  }
  waitpid(0, NULL, NULL);
  for (int i = 0; i < index; ++i) {
    free(args[i]);
  }
  return 0;
#else
  alpm_list_t *i;
  int ret = 0;
  for (i = pkgs; i; i = alpm_list_next(i)) {
    alpm_pkg_t *pkg = (alpm_pkg_t *)i->data;
    if (install(pkg)) {
      ret = 1;
    } else {
      hash_add(hash_compute(pkg));
    }
  }
  return ret;
#endif
}

/* @brief remove the package and then update
 *  the hash table and Trie
 * @param pkg the target package
 * @return 0 if succeed 1 if not
 */
int operation::remove(alpm_pkg_t *pkg) {
  alpm_list_t *data = nullptr;
  char *pkg_name = strdup(alpm_pkg_get_name(pkg));
  /* don't check dependences */
  int ret;
  ret = alpm_trans_init(conf->handle, ALPM_TRANS_FLAG_NODEPS);
  if (ret) {
    free(pkg_name);
    alpm_trans_release(conf->handle);
    return 1;
  }
  ret = alpm_remove_pkg(conf->handle, pkg);
  if (ret) {
    free(pkg_name);
    alpm_trans_release(conf->handle);
    return 1;
  }
  ret = alpm_trans_prepare(conf->handle, &data);
  if (ret) {
    free(pkg_name);
    alpm_trans_release(conf->handle);
    return 1;
  }
  ret = alpm_trans_commit(conf->handle, &data);
  if (ret) {
    free(pkg_name);
    alpm_trans_release(conf->handle);
    return 1;
  }
  alpm_trans_release(conf->handle);

  hash_remove(hash_compute(pkg_name));
  trie_remove(Trie->local, pkg_name);
  FREELIST(data);
  free(pkg_name);
  return 0;
}
/* @brief check whether the targe package have been installed
 * @param pkg the target
 * @return 1 if installed 0 if not
 */
int operation::check_installed(alpm_pkg_t *pkg) {
#ifdef SEARCH_LOCAL_WITH_HASH
  return phs[hash_compute(pkg)];

#else
  alpm_db_t *localdb = alpm_get_localdb(conf->handle);
  alpm_list_t *pkgcache = alpm_db_get_pkgcache(localdb);

  /* check if pkg have been in the local database */
  alpm_list_t *i;
  for (i = pkgcache; i; i = alpm_list_next(i)) {
    alpm_pkg_t *p = (alpm_pkg_t *)i->data;
    if (strcmp(alpm_pkg_get_name(p), alpm_pkg_get_name(pkg)) == 0) {
      if (alpm_pkg_vercmp(alpm_pkg_get_version(p), alpm_pkg_get_version(pkg))) {
        return 0;
      } else
        return 1;
    }
  }
  return 0;
#endif
}

/* @brief check the local database to check whethe the list of packages
 *      have all been installed
 * @param list the target's name list
 * @return a list of package haven't been installed from the input list
 */
alpm_list_t *operation::check_noinstalled(alpm_list_t *list) {
  alpm_list_t *ret = nullptr;
  alpm_pkg_t *p;
  alpm_list_t *i;
  for (i = list; i; i = alpm_list_next(i)) {
    char *pkg_name = (char *)i->data;
#ifdef SEARCH_LOCAL_WITH_HASH
    if (!phs[hash_compute(pkg_name)]) {
#else
    p = get_localpkg(pkg_name);
    if (!p) {
#endif
      p = find_dbs_pkg(alpm_get_syncdbs(conf->handle), pkg_name);
      if (p)
        ret = alpm_list_add(ret, p);
    }
  }
  return ret;
}
/* @brief check the input list to select the packages that
 *   bave been installed and return their name as a list
 * @param list the target list to check
 * @return a list of (char*)
 */
alpm_list_t *operation::check_installed(alpm_list_t *list) {
  alpm_list_t *ret = nullptr;
  alpm_list_t *i;
  for (i = list; i; i = alpm_list_next(i)) {
    alpm_pkg_t *pkg = (alpm_pkg_t *)i->data;
    if (phs[hash_compute(pkg)]) {
      ret = alpm_list_add(ret, get_localpkg(alpm_pkg_get_name(pkg)));
    }
  }
  return ret;
}

/*---------------------------DEPENDENCE--------------------------*/
/* @brief check the local packages and select packages which have
 *   miss dependencies , then return them as a list of packages
 * @return a list of local packages
 */
alpm_list_t *operation::get_missdeps() {
  alpm_list_t *ret = nullptr;
  alpm_list_t *localpkgs = get_installed_pkgs();
  alpm_list_t *i;
  for (i = localpkgs; i; i = alpm_list_next(i)) {
    alpm_pkg_t *pkg = (alpm_pkg_t *)i->data;
    if (get_pkg_unresolve_depend(pkg)) {
      ret = alpm_list_add(ret, pkg);
    }
  }
  return ret;
}
/* @brief get a list of (alpm_depend_t*) of  a package
 * @return a list of (alpm_depend_t*)
 */
alpm_list_t *operation::get_pkg_depend(alpm_pkg_t *pkg) {
  return alpm_pkg_get_depends(pkg);
}

/* @brief loop for check deep dependencies
 * @param pkg the target package
 * @return a list of sync packages
 */
alpm_list_t *operation::get_pkg_unresolve_depend(alpm_pkg_t *pkg) {
  int dsu_len = 1000;
  int *far = dsu_init(dsu_len);
  std::queue<alpm_pkg_t *> pkg_queue;
  alpm_list_t *unresolve = nullptr;
  pkg_queue.push(pkg);
  dsu_make(far, pkg, 0, dsu_len);

  while (!pkg_queue.empty()) {
    alpm_pkg_t *tar_pkg = pkg_queue.front();
    pkg_queue.pop();
    alpm_list_t *depend = get_pkg_depend(tar_pkg);
    alpm_list_t *i;
    const char *name;
    /* loop depend_t */
    for (i = depend; i; i = alpm_list_next(i)) {
      name = ((alpm_depend_t *)i->data)->name;
      if (!get_localpkg(name)) {
        if (dsu_find(far, hash_compute(name) % dsu_len) ==
            dsu_find(far, pkg, dsu_len)) {
          continue;
        }
        alpm_list_t *dbs = alpm_get_syncdbs(conf->handle);
        alpm_pkg_t *p = find_dbs_pkg(dbs, name);
        if (p) {
          unresolve = alpm_list_add(unresolve, p);
          pkg_queue.push(p);
          break;
        }
      }
    }
  }
  dsu_release(far);
  return unresolve;
}
alpm_list_t *operation::get_pkg_optdepend(alpm_pkg_t *pkg) {
  alpm_list_t *opt = alpm_pkg_get_optdepends(pkg);
  return opt;
}

/* @brief get a list of packages which depend on the target package
 * @param p the target package
 * @return a list of packages
 */
alpm_list_t *operation::get_pkg_require(alpm_pkg_t *p) {
  alpm_list_t *ret = nullptr, *localp = get_installed_pkgs(), *i;
  const char *name = alpm_pkg_get_name(p);
  for (i = localp; i; i = alpm_list_next(i)) {
    alpm_pkg_t *pkg = (alpm_pkg_t *)i->data;
    alpm_list_t *deps = alpm_pkg_get_depends(pkg);
    alpm_list_t *j;
    for (j = deps; j; j = alpm_list_next(j)) {
      alpm_depend_t *d = (alpm_depend_t *)j->data;
      if (strcmp(name, d->name) == 0) {
        ret = alpm_list_add(ret, pkg);
        break;
      }
    }
  }
  return ret;
}

/* @brief return a list of package that installed as
 *    a dependency of other package which have been
 *    removed now.
 * @return a list of packages
 */
alpm_list_t *operation::get_orphans() {
  alpm_list_t *ret = nullptr;
  alpm_list_t *localpkgs = get_installed_pkgs();
  alpm_list_t *i;
  for (i = localpkgs; i; i = alpm_list_next(i)) {
    alpm_pkg_t *pkg = (alpm_pkg_t *)i->data;
    alpm_pkgreason_t reason = alpm_pkg_get_reason(pkg);
    if (reason == ALPM_PKG_REASON_DEPEND) {
      if (!get_pkg_require(pkg)) {
        ret = alpm_list_add(ret, pkg);
      }
    }
  }
  return ret;
}
/*---------------------------PKG FILES--------------------------*/
alpm_list_t *operation::get_pkg_files(alpm_pkg_t *pkg) {
  alpm_list_t *ret = nullptr;
  alpm_filelist_t *pkgfiles = alpm_pkg_get_files(pkg);
  size_t i;
  for (i = 0; i < pkgfiles->count; ++i) {
    const alpm_file_t *file = pkgfiles->files + i;
    char *file_path = (char *)calloc(1, FILE_LEN);
    strcat(file_path, conf->root);
    strcat(file_path, file->name);
    ret = alpm_list_add(ret, file_path);
  }
  return ret;
}
alpm_list_t *operation::get_pkg_missfiles(alpm_pkg_t *pkg) {
  alpm_list_t *ret = nullptr;
  alpm_list_t *files = get_pkg_files(pkg);
  alpm_list_t *i;
  for (i = files; i; i = alpm_list_next(i)) {
    if (!check_file((char *)i->data)) {
      ret = alpm_list_add(ret, (char *)i->data);
    }
  }
  return ret;
}

/*---------------------PKG NOTE--------------------------*/
int operation::set_pkg_note(alpm_pkg_t *pkg, const char *note) {
  char *path = (char *)calloc(1, sizeof(char) * FILE_LEN);
  strcat(path, conf->notepath);
  strcat(path, alpm_pkg_get_name(pkg));
  std::ofstream fs;
  fs.open(path, std::ofstream::out | std::ofstream::trunc);
  if (!fs.is_open()) {
    free(path);
    return 1;
  }
  fs << note << std::endl;
  fs.close();
  free(path);
  return 0;
}
char *operation::get_pkg_note(alpm_pkg_t *pkg) {
  char *path = (char *)calloc(1, sizeof(char) * FILE_LEN);
  strcat(path, conf->notepath);
  strcat(path, alpm_pkg_get_name(pkg));
  std::ifstream fs;
  fs.open(path, std::ifstream::in);
  if (!fs.is_open())
    return nullptr;

  fs.seekg(0, std::ios::end);
  int length = fs.tellg();
  char *content = (char *)calloc(1, sizeof(char) * length);
  fs.seekg(0, std::ios::beg);
  fs.read(content, length);
  fs.close();
  free(path);
  return content;
}
/*---------------------HASH-------------------*/
pkg_hash operation::hash_compute(const char *name) {
  pkg_hash hashB = 334;
  const char *i;
  pkg_hash ret = 0;
  pkg_hash b = hashB;
  for (i = name; *i != '\0'; ++i) {
    ret = (ret + (*i * b)) % HASH_LEN;
    b = (b * b) % HASH_LEN;
  }
  return ret;
}
pkg_hash operation::hash_compute(alpm_pkg_t *pkg) {
  if (!pkg)
    return 0;
  return hash_compute(alpm_pkg_get_name(pkg));
}
pkg_hash operation::hash_add(pkg_hash h) {
  phs[h] = true;
  return h;
}
pkg_hash operation::hash_remove(pkg_hash h) {
  phs[h] = false;
  return h;
}

/*----------------------OTHER---------------------------*/
/* return the correct database with @param sdb */
int operation::match_db(alpm_db_t *db, int sdb) {
  if ((sdb & CORE) && strcmp(alpm_db_get_name(db), "core") == 0) {
    return CORE;
  } else if ((sdb & COMMUNITY) &&
             strcmp(alpm_db_get_name(db), "community") == 0) {
    return COMMUNITY;
  } else if ((sdb & EXTRA) && strcmp(alpm_db_get_name(db), "extra") == 0) {
    return EXTRA;
  } else if ((sdb & LOCAL) && strcmp(alpm_db_get_name(db), "local") == 0) {
    return LOCAL;
  }
  return false;
}
operation::~operation() { delete conf; }
/* @brief mark the input list of package's install reason
 *  as a dependency
 *  @param list the target list
 */
void operation::mark_as_dep(alpm_list_t *list) {
  alpm_list_t *i;
  for (i = list; i; i = alpm_list_next(i)) {
    alpm_pkg_t *pkg = (alpm_pkg_t *)i->data;
    if (check_installed(pkg)) {
      alpm_pkg_set_reason(pkg, ALPM_PKG_REASON_DEPEND);
    }
  }
}
bool operation::cmp_pkg(alpm_pkg_t *p1, alpm_pkg_t *p2) {
  return hash_compute(p1) == hash_compute(p2);
}
/* @brief check whether the version of installed package is higher than target
 * @return true if have, false if not
 */
bool operation::check_higher_version(alpm_pkg_t *pkg) {
  alpm_list_t *pkgcache = alpm_db_get_pkgcache(alpm_get_localdb(conf->handle));
  alpm_list_t *i;
  for (i = pkgcache; i; i = alpm_list_next(i)) {
    alpm_pkg_t *p = (alpm_pkg_t *)i->data;
    if (cmp_pkg(p, pkg)) {
      return alpm_pkg_vercmp(alpm_pkg_get_version(pkg),
                             alpm_pkg_get_version(p)) <= 0;
    }
  }
  return false;
}
/* @brief get a list of packages can be updated
 * @return a list of packages
 */
alpm_list_t *operation::get_pkgs_sysupdate() {
  int ret = alpm_trans_init(conf->handle, 0);
  if (ret)
    return nullptr;
  alpm_list_t *data;
  ret = alpm_trans_prepare(conf->handle, &data);
  ret = alpm_sync_sysupgrade(conf->handle, 0);
  alpm_list_t *list = alpm_list_copy(alpm_trans_get_add(conf->handle));
  alpm_trans_release(conf->handle);
  return list;
}
/* @return the database have been update */
alpm_list_t *operation::database_update(int force) {
  alpm_list_t *ret = nullptr;
  alpm_list_t *syncdbs = alpm_get_syncdbs(conf->handle);
  alpm_list_t *i;
  for (i = syncdbs; i; i = alpm_list_next(i)) {
    alpm_db_t *db = (alpm_db_t *)i->data;
    int flag = alpm_db_update(force, db);
    if (flag == 1) {
      /* if the database had been newest */
      ret = alpm_list_add(ret, db);
    } else if (flag == 0) {
      /* the database have been download */
      if (!alpm_db_get_valid(db))
        ret = alpm_list_add(ret, db);
    } else {
      fprintf(stdout, "%s\n", alpm_strerror(alpm_errno(conf->handle)));
    }
  }
  /* release trie */
  trie_release(Trie->local);
  trie_release(Trie->core);
  trie_release(Trie->community);
  trie_release(Trie->extra);
  free(Trie);
  /* setup a new trie */
  trie_init();

  /* clean up the .sig file */
  clean_sig(conf->handle);
  return ret;
}
/*-------------------Trie-------------------*/

/* @brief seach a list of node to find out a node
 *      contains the target char
 * @param list a list of trie_node*
 * @param t the target char
 */
static trie_node *list_find_char(alpm_list_t *list, char t) {
  alpm_list_t *i;
  for (i = list; i; i = alpm_list_next(i)) {
    trie_node *node = (trie_node *)i->data;
    if (node->type == 2 && node->alpha == t)
      return node;
  }
  return nullptr;
}
/* @brief initialize the trie with all packages */
void operation::trie_init() {
  Trie = (trie_root *)calloc(1, sizeof(trie_root));
  alpm_list_t *dbs;
  dbs = alpm_get_syncdbs(conf->handle);
  dbs = alpm_list_add(dbs, alpm_get_localdb(conf->handle));
  alpm_list_t *i;
  for (i = dbs; i; i = alpm_list_next(i)) {
    trie_node *db_root = (trie_node *)calloc(1, sizeof(trie_node));
    if (match_db((alpm_db_t *)i->data, CORE))
      Trie->core = db_root;
    else if (match_db((alpm_db_t *)i->data, COMMUNITY))
      Trie->community = db_root;
    else if (match_db((alpm_db_t *)i->data, EXTRA))
      Trie->extra = db_root;
    else if (match_db((alpm_db_t *)i->data, LOCAL))
      Trie->local = db_root;
    alpm_list_t *pkgs = alpm_db_get_pkgcache((alpm_db_t *)i->data);
    alpm_list_t *j;
    for (j = pkgs; j; j = alpm_list_next(j)) {
      trie_add(db_root, (alpm_pkg_t *)j->data);
    }
  }
}
/* @brief search the trie with the name of package and return
 *      node that point to the package
 * @param root which database to search
 * @param pkg the target package
 * @return a node
 */
trie_node *operation::trie_find(trie_node *root, alpm_pkg_t *pkg) {
  const char *name = alpm_pkg_get_name(pkg);
  return trie_find(root, name);
}
trie_node *operation::trie_find(trie_node *root, const char *name) {
  int i = 0;
  int len = strlen(name);
  trie_node *fa = root;
  while (fa && i < len) {
    fa = list_find_char(fa->child, name[i]);
    ++i;
  }
  if (fa) {
    return fa;
  }
  return nullptr;
}
void operation::trie_remove(trie_node *root, alpm_pkg_t *pkg) {
  trie_node *node = trie_find(root, pkg);
  node->child = nullptr;
}
void operation::trie_remove(trie_node *root, const char *name) {
  trie_node *node = trie_find(root, name);
  node->child = nullptr;
}
/* @brief add package to trie
 * @param root which database to operate
 * @param pkg which package to be added
 */
void operation::trie_add(trie_node *root, alpm_pkg_t *pkg) {
  const char *name = alpm_pkg_get_name(pkg);
  int i = 0, len = strlen(name);
  trie_node *fa = root;
  while (i < len) {
    trie_node *tmp = list_find_char(fa->child, name[i]);
    if (tmp)
      fa = tmp;
    else {
      trie_node *new_node = (trie_node *)calloc(1, sizeof(trie_node));
      new_node->alpha = name[i];
      new_node->type = 2;
      fa->child = alpm_list_add(fa->child, new_node);
      fa = new_node;
    }
    i++;
  }
  if (!fa->child) {
    trie_node *new_node = (trie_node *)calloc(1, sizeof(trie_node));
    new_node->type = 3;
    new_node->pkg = pkg;
    fa->child = alpm_list_add(fa->child, new_node);
  }
}
/* @brief release the trie node
 * @param node which node to be released, often
 *      indicate a database
 */
void operation::trie_release(trie_node *node) {
  alpm_list_t *i;
  for (i = node->child; i; i = alpm_list_next(i)) {
    trie_release((trie_node *)i->data);
  }
  if (node && node->type != 3)
    free(node);
}
/* @brief collect the packages who are the offspring
 *      of the node
 * @param node the target node to collect packages
 * @return a list of packages
 */
static alpm_list_t *_trie_clt(trie_node *node) {
  alpm_list_t *ret = nullptr;
  if (!node)
    return ret;
  if (node->type == 2) {
    alpm_list_t *i;
    for (i = node->child; i; i = alpm_list_next(i)) {
      ret = alpm_list_join(ret, _trie_clt((trie_node *)i->data));
    }
  }
  if (node->type == 3) {
    ret = alpm_list_add(ret, node->pkg);
  }
  return ret;
}
/* @brief collect the packages, refered at _trie_clt.
 */
alpm_list_t *operation::trie_clt(trie_node *root, const char *name) {
  int i = 0, len = strlen(name);
  trie_node *fa = root;
  while (i < len) {
    if (!fa) {
      break;
    }
    fa = list_find_char(fa->child, name[i]);
    i++;
  }
  return _trie_clt(fa);
}
/* @brief used for debug */
void operation::trie_debug(trie_node *node) {
  if (!node)
    return;
  if (node->type == 2) {
    fprintf(stdout, "%c->", node->alpha);
  }
  if (node->type == 3) {
    fprintf(stdout, "%s", alpm_pkg_get_name(node->pkg));
    return;
  }
  fprintf(stdout, "(");
  alpm_list_t *i;
  for (i = node->child; i; i = alpm_list_next(i)) {
    trie_debug((trie_node *)i->data);
  }
  fprintf(stdout, ")");
  return;
}
/*-----------------------DSU--------------------*/
int *operation::dsu_init(int size) {
  int *fa = (int *)calloc(1, sizeof(int) * size);
  for (int i = 0; i < size; ++i) {
    fa[i] = i;
  }
  return fa;
}
void operation::dsu_release(int *dsu) { free(dsu); }
int operation::dsu_find(int *dsu, pkg_hash hash) {
  return dsu[hash] == hash ? hash : dsu[hash] = dsu_find(dsu, dsu[hash]);
}
int operation::dsu_find(int *dsu, alpm_pkg_t *pkg, int size) {
  pkg_hash h = hash_compute(pkg) % size;
  return dsu_find(dsu, h);
}
void operation::dsu_make(int *dsu, alpm_pkg_t *p1, alpm_pkg_t *p2, int size) {
  int h1 = dsu_find(dsu, p1, size), h2 = dsu_find(dsu, p2, size);
  dsu_make(dsu, h1, h2);
}
void operation::dsu_make(int *dsu, pkg_hash h1, pkg_hash h2) { dsu[h1] = h2; }
