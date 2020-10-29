/*
 *  interface.h
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
#ifndef INTERFACE_H
#define INTERFACE_H

#include "conf.h"
#include "util.h"
#include "debug.h"

#include <alpm.h>
#include <alpm_list.h>

typedef unsigned long long pkg_hash;
/* the length of hash table,
 * to avoid conflicts, the 
 * length should as large
 * as possible
 */
#define  HASH_LEN 10000000


/* which database to operate */
enum {
        CORE = (1<<0),
        EXTRA = (1<<1),
        COMMUNITY = (1<<2),
        LOCAL = (1<<3),
        ALL = (1<<4)-1
};

/* DAG depend tree */
struct pkg_depend {
        alpm_pkg_t* pkg = nullptr;
        alpm_list_t* depend_on = nullptr;
};
/* Trie */
struct trie_node {
        /* 0 for the Trie;
         * 1 for the database;
         * 2 for the common node
         * 3 for the package node
         */
        int type;
        union {
                char alpha;
                alpm_pkg_t* pkg;
        };
        alpm_list_t* child;
};
enum {
        PKG_OK = 1<<0,
        PKG_UPGRADE = 1<<1,
        PKG_INSTALL = 1<<2,
        PKG_REMOVE = 1<<3,
};
struct trie_root {
        trie_node* local;
        trie_node* core;
        trie_node* community;
        trie_node* extra;
};

class operation {
public:
        conf_t* conf ;
        bool phs[HASH_LEN];
        trie_root* Trie;
        /*---------PACKAGE FUNCTION------------*/
        alpm_list_t* get_pkgs_by_regex(const char*,int);
        alpm_list_t* get_pkgs_by_KMP(const char*,int);
        alpm_list_t* get_pkgs_by_Trie(const char*,int);
        alpm_list_t* get_installed_pkgs();
        alpm_list_t* get_conflicts(alpm_pkg_t*);
        alpm_list_t* get_pkg_missfiles(alpm_pkg_t*);
        alpm_list_t* get_pkg_missdeps(alpm_pkg_t*);
        alpm_list_t* get_pkg_require(alpm_pkg_t*);
        alpm_pkg_t* get_localpkg(const char*);
        alpm_list_t* get_pkg_unresolve_depend(alpm_pkg_t*);
        alpm_list_t* get_pkg_depend(alpm_pkg_t*);
        alpm_list_t* get_pkg_optdepend(alpm_pkg_t*);
        alpm_list_t* get_pkg_files(alpm_pkg_t*);
        int to_change_pkg(alpm_pkg_t*,int);
        int install_list(alpm_list_t*);
        int remove(alpm_pkg_t*);
        bool cmp_pkg(alpm_pkg_t*,alpm_pkg_t*);
        int set_pkg_note(alpm_pkg_t*, const char*);
        char* get_pkg_note(alpm_pkg_t*);
        alpm_list_t* check_noinstalled(alpm_list_t*);
        alpm_list_t* check_installed(alpm_list_t*);
        int check_installed(alpm_pkg_t*);
        bool check_higher_version(alpm_pkg_t*);
        alpm_pkg_t* find_dbs_pkg(alpm_list_t*,const char*);
        bool find_chars_pkg(alpm_list_t*,alpm_pkg_t*);
        int install(alpm_pkg_t*);

        /*---------------OTHER--------------*/
        alpm_list_t* get_orphans();
        alpm_list_t* get_missdeps();
        alpm_list_t* database_update(int);
        alpm_list_t* get_pkgs_sysupdate();
        int clean_pkgcache();
        void mark_as_dep(alpm_list_t*);
        int match_db(alpm_db_t*, int);

        /*---------------HASH---------------*/
        pkg_hash hash_compute(const char*);
        pkg_hash hash_compute(alpm_pkg_t*);
        pkg_hash hash_add(pkg_hash);
        pkg_hash hash_remove(pkg_hash);

        /*---------------Trie---------------*/
        void trie_init();
        void trie_add(trie_node*,alpm_pkg_t*);
        trie_node* trie_find(trie_node*,alpm_pkg_t*);
        trie_node* trie_find(trie_node*,const char*);
        void trie_release(trie_node*);
        void trie_debug(trie_node*);
        void trie_remove(trie_node*,alpm_pkg_t*);
        void trie_remove(trie_node*, const char*);
        alpm_list_t* trie_clt(trie_node*,const char*);

        /*---------------DSU-----------------*/
        int *dsu_init(int size=HASH_LEN);
        void dsu_release(int* dsu);
        int dsu_find(int*,pkg_hash);
        int dsu_find(int*,alpm_pkg_t*,int size = HASH_LEN);
        void dsu_make(int* ,alpm_pkg_t*,alpm_pkg_t*,int size=HASH_LEN);
        void dsu_make(int*,pkg_hash,pkg_hash);

        operation();
        ~operation();
};
#endif
