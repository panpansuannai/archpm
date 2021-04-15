/*
 *  util.cpp
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
#include "util.h"
#include "conf.h"

#include <cctype>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

int check_uid() {
  int uid = getuid();
  if (uid != 0) {
    return 1;
  }
  return 0;
}
/* dump the string to a char array */
void stchar(char **c, std::string s) {
  *c = (char *)calloc(1, CLEN);
  strncpy(*c, s.c_str(), CLEN);
}

/* dump a string splited by space to a alpm_list */
alpm_list_t *str_split(const char *orignal) {
  int last = 0;
  alpm_list_t *ret = nullptr;
  for (int i = 0; i < strlen(orignal); ++i) {
    if (*(orignal + i) == ' ' && i != last) {
      ret = alpm_list_add(ret, strndup(orignal + last, i - last));
      last = i + 1;
    }
  }
  if (last != strlen(orignal) - 1)
    ret = alpm_list_add(ret, strdup(orignal + last));
  return ret;
}

int rm_file(const char *path) {
  if (check_file(path)) {
    return unlink(path);
  }
  return 1;
}

void clean_up(void) { rm_file("/var/lib/pacman/db.lck"); }
void clean_sig(alpm_handle_t *handle) {
  char *path = (char *)calloc(1, sizeof(char *) * 1024);
  alpm_list_t *dbs = alpm_get_syncdbs(handle);
  for (; dbs; dbs = alpm_list_next(dbs)) {
    memset(path, 0, sizeof(char *) * 1024);
    strcat(path, alpm_option_get_dbpath(handle));
    strcat(path, "sync/");
    strcat(path, alpm_db_get_name((alpm_db_t *)dbs->data));
    strcat(path, ".db.sig");

    rm_file(path);
  }
}

bool check_file(const char *file) {
  int ret = access(file, F_OK);
  return ret == 0;
}
alpm_list_t *copy_pkgs_name(alpm_list_t *list) {
  alpm_list_t *i;
  alpm_list_t *ret = nullptr;
  for (i = list; i; i = alpm_list_next(i)) {
    alpm_pkg_t *pkg = (alpm_pkg_t *)i->data;
    char *name = strdup(alpm_pkg_get_name(pkg));
    ret = alpm_list_add(ret, name);
  }
  return ret;
}

void free_list_char(alpm_list_t *cs) {
  alpm_list_t *i;
  for (i = cs; i; i = alpm_list_next(i)) {
    char *c = (char *)i->data;
    free(c);
  }
}
alpm_list_t *string_to_list(const char *s) {
  alpm_list_t *ret = nullptr;
  char *item = nullptr;
  int i = 0;
  int feet;
  while (s[i] != '\0') {
    if (isalnum(s[i]) || s[i] == '/') {
      if (!item) {
        item = (char *)calloc(1, sizeof(char) * 512);
        feet = 0;
      }
      item[feet++] = s[i];
    } else {
      if (item) {
        ret = alpm_list_add(ret, item);
        item = nullptr;
      }
    }
    ++i;
  }
  if (item)
    ret = alpm_list_add(ret, item);
  return ret;
}
char *get_size(int i) {
  char *size = (char *)calloc(1, sizeof(char) * 512);
  int a = i / 1000000;
  int b = (i % 1000000) / 100000;
  int c = (i % 100000) / 10000;
  sprintf(size, "%d.%d%dMB", a, b, c);
  return size;
}
/* Replace all occurrences of 'needle' with 'replace' in 'str', returning
 * a new string (must be free'd) */
char *strreplace(const char *str, const char *needle, const char *replace) {
  const char *p = NULL, *q = NULL;
  char *newstr = NULL, *newp = NULL;
  alpm_list_t *i = NULL, *list = NULL;
  size_t needlesz = strlen(needle), replacesz = strlen(replace);
  size_t newsz;

  if (!str) {
    return NULL;
  }

  p = str;
  q = strstr(p, needle);
  while (q) {
    list = alpm_list_add(list, (char *)q);
    p = q + needlesz;
    q = strstr(p, needle);
  }

  /* no occurrences of needle found */
  if (!list) {
    return strdup(str);
  }
  /* size of new string = size of old string + "number of occurrences of needle"
   * x "size difference between replace and needle" */
  newsz = strlen(str) + 1 + alpm_list_count(list) * (replacesz - needlesz);
  newstr = (char *)calloc(newsz, sizeof(char));
  if (!newstr) {
    return NULL;
  }

  p = str;
  newp = newstr;
  for (i = list; i; i = alpm_list_next(i)) {
    q = (const char *)i->data;
    if (q > p) {
      /* add chars between this occurrence and last occurrence, if any */
      memcpy(newp, p, (size_t)(q - p));
      newp += q - p;
    }
    memcpy(newp, replace, replacesz);
    newp += replacesz;
    p = q + needlesz;
  }
  alpm_list_free(list);

  if (*p) {
    /* add the rest of 'p' */
    strcpy(newp, p);
  }

  return newstr;
}
