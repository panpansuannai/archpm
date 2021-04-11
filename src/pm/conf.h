/*
 *  conf.h
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
#pragma once

#include <alpm.h>
#include "cb.h"

/* length of buffer */
#define BS 1024
/* the maxlength of a path */
#define CLEN 512
/* the maxlength of a url */
#define ULEN 2048

/* default configure */
#define DEF_ROOT  "/" 
#define DEF_CACHEDIRS "/var/cache/archpm/pkg/" 
#define DEF_ARCH "x86_64" 
#define DEF_CONFFILE "/etc/pacman.conf" 
#define DEF_SERVER "http://mirrors.163.com/archlinux" 
#define DEF_DBPATH "/var/lib/pacman/" 
#define DEF_HOOKDIR "/etc/pacman.d/hooks/"
#define DEF_LOGFILE "/var/log/archpm.log" 
#define DEF_GPGDIR "/etc/pacman.d/gnupg/" 
#define DEF_NOTE "/var/lib/archpm/"

#define REP_REPO "$repo" 
#define REP_ARCH "$arch" 

/* to initialize the servers */
struct repo_t {
        char* name;
        alpm_list_t * server;
        alpm_siglevel_t siglevel;
};

struct option_t {
        char* name ;
        char* rootdir ;
        char* dbpath ;
        char* cachedirs ;
        char* logfile ;
        char* gpgdir ;
        char* hookdir ;
        char* arch ;

        /** need to be parsed again, because they 
         * may contain more than one params.
         */
        char* holdpkgs ;
        char* ignorepkgs ;
        char* ignoregrps ;
        char* noupgrades ;
        char* noextracts ;

        alpm_siglevel_t siglevel;
        alpm_siglevel_t localfilesig;
        alpm_siglevel_t remotesig;
        
        int usesyslog;
        int checkspace;

};

class conf_t {
public:
        conf_t();
        conf_t(const char* file);
        ~conf_t();

        alpm_handle_t *handle;  
        alpm_list_t * repos;
        option_t *option;
        
        /*----------SETUP MEMBER-------------*/
        alpm_siglevel_t siglevel;
        char *logfile = nullptr;  /* where to do log action*/
        char *arch = nullptr;  
        char *gpgdir = nullptr; 
        char *hookdir = nullptr;
        char *conffile = nullptr;
        char *notepath = nullptr;

        alpm_list_t *holdpkgs = nullptr;
        alpm_list_t *cachedirs = nullptr;  /* where to save cache packages */
        alpm_list_t *noextracts = nullptr;
        alpm_list_t *noupgrades = nullptr;
        alpm_list_t *ignorepkgs = nullptr;
        alpm_list_t *ignoregrps = nullptr;
        
        /*----------INTERFACE-------------*/
        int conf_set_root(char*);
        int conf_set_dbpath(char*);
        int conf_set_logfile(char*);
        int conf_set_arch(char*);
        int conf_set_gpgdir(char*);
        int conf_set_hookdir(char*);
        int conf_set_cachedirs(alpm_list_t*);
        int conf_set_noextracts(alpm_list_t*);
        int conf_set_noupgrades(alpm_list_t*);
        int conf_set_ignorepkgs(alpm_list_t*);
        int conf_set_ignoregrps(alpm_list_t*);
        int conf_set_holdpkgs(alpm_list_t*);
        int conf_parsefile(const char *);
        void conf_set_option();

        /*--------SETUP HANDLE---------*/
        int conf_set_handle();
        int conf_hd_init_syncdbs();

        /*--------IMPORTANT-----------*/
        char *root = nullptr; /* root of file system */
        char *dbpath = nullptr;  /* file path of data base */
        char *lockfile = nullptr; /* mutex of data base */

};
