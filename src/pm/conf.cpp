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
#include "conf.h"
#include "cb.h"
#include "parse.h"
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <alpm.h>
#include <alpm_list.h>

static void set_callback(conf_t* config)
{
        /* setup the callback functions */
        alpm_option_set_logcb( config->handle,cb_log);
        alpm_option_set_dlcb( config->handle,cb_dl);
        alpm_option_set_eventcb( config->handle,cb_event);
        alpm_option_set_questioncb( config->handle,cb_quest);
        alpm_option_set_progresscb( config->handle,cb_prog);
        alpm_option_set_fetchcb( config->handle,cb_fetch);
        alpm_option_set_totaldlcb( config->handle,cb_tdl);
}

/*---------------------set up conf_t----------------------*/
int conf_t::conf_set_holdpkgs(alpm_list_t* list)
{
        FREELIST(holdpkgs);
        holdpkgs =  list;
        return 0;
}
int conf_t::conf_set_root(char* rootpath)
{
        free(root);
        root = rootpath;
        return 0;
}

int conf_t::conf_set_logfile(char* log)
{
        free(logfile);
        logfile = log;
        return 0;
}
int conf_t::conf_set_dbpath(char *db)
{
        free(dbpath);
        dbpath = db;
        return 0;
}
int conf_t::conf_set_arch(char* ar)
{
        free(arch);
        arch = ar;
        return 0;
}
int conf_t::conf_set_gpgdir(char* gpgpath)
{
        free(gpgdir);
        gpgdir = gpgpath;
        return 0;
}
int conf_t::conf_set_cachedirs(alpm_list_t *list)
{
        FREELIST(this->cachedirs);
        alpm_list_t* i;
        for(i=list;i;i=alpm_list_next(i)){
                char* filePath = (char*)i->data;
                if(!check_file(filePath)){
                        mkdir(filePath,S_IRWXU|S_IRWXO|S_IRWXG);
                }
        }
        this->cachedirs = list;
        return 0;
}
int conf_t::conf_set_noextracts(alpm_list_t *list)
{
        FREELIST(this->noextracts);
        this->noextracts = list;
        return 0;
}
int conf_t::conf_set_noupgrades(alpm_list_t *list)
{
        FREELIST(this->noupgrades);
        this->noupgrades = list;
        return 0;
}
int conf_t::conf_set_ignorepkgs(alpm_list_t *list)
{
        FREELIST(this->ignorepkgs);
        this->ignorepkgs = list;
        return 0;
}
int conf_t::conf_set_ignoregrps(alpm_list_t *list)
{
        FREELIST(this->ignoregrps);
        this->ignoregrps = list;
        return 0;
}
int conf_t::conf_set_hookdir(char* hookpath)
{
        free(hookdir);
        hookdir = hookpath;
        return 0;
}

/* set up handle with conf_t */
int conf_t::conf_set_handle()
{
        int flag;
        flag = alpm_option_set_logfile(this->handle,this->logfile);
        if(flag){
                fprintf(stderr,"Error:setup Logfile failed!\n");
                return 1;
        }

        flag = alpm_option_set_gpgdir(this->handle,this->gpgdir);
        if(flag){
                fprintf(stderr,"Error:setup gpgdir failed!\n");
                return 1;
        }

        alpm_list_t* list = alpm_list_add(nullptr,this->hookdir);
        flag = alpm_option_set_hookdirs(this->handle,list);
        if(flag){
                fprintf(stderr,"Error:setup hookdir failed!\n");
                return 1;
        }

        flag = alpm_option_set_cachedirs(this->handle,this->cachedirs);
        if(flag){
                fprintf(stderr,"Error:setup cachedirs failed!\n");
                return 1;
        }

        flag = alpm_option_set_noextracts(this->handle,this->noextracts);
        if(flag){
                fprintf(stderr,"Error:setup noextracts failed!\n");
                return 1;
        }

        flag = alpm_option_set_noupgrades(this->handle,this->noupgrades);
        if(flag){
                fprintf(stderr,"Error:setup noupgrades failed!\n");
                return 1;
        }


        flag = alpm_option_set_ignorepkgs(this->handle,this->ignorepkgs);
        if(flag){
                fprintf(stderr,"Error:setup ignorepkgs failed!\n");
                return 1;
        }


        flag = alpm_option_set_ignoregroups(this->handle,this->ignoregrps);
        if(flag){
                fprintf(stderr,"Error:setup ignoregrps failed!\n");
                return 1;
        }


        alpm_option_set_usesyslog(this->handle,0);

        alpm_option_set_arch(this->handle,this->arch);
        
        alpm_option_set_default_siglevel(this->handle,ALPM_SIG_USE_DEFAULT);
        return 0;
}
/* constructor */
conf_t::conf_t()
{
        logfile = strdup(DEF_LOGFILE);
        arch = strdup(DEF_ARCH);
        gpgdir = strdup(DEF_GPGDIR);
        hookdir = strdup(DEF_HOOKDIR);
        conffile = strdup(DEF_CONFFILE);
        notepath = strdup(DEF_NOTE);
        dbpath = strdup(DEF_DBPATH);
        root = strdup(DEF_ROOT);
        cachedirs = string_to_list(DEF_CACHEDIRS);
        
        repos = nullptr;
        option = nullptr;
        alpm_errno_t err;
        handle = alpm_initialize(root,dbpath,&err);
        if(!handle){
                fprintf(stdout,"Initialize handle fail!");
                exit(1);
        }

        set_callback(this);
        conf_parsefile(conffile);
        conf_set_option();
        conf_set_handle();

        conf_hd_init_syncdbs();

        FREELIST(pd);
}

/* parse the file to get option */
int conf_t::conf_parsefile(const char* path)
{
        if(!check_file(path)){
                fprintf(stdout,"configure file %s doesn't exit",path);
                return 1;
        }
        std::fstream fs;
        fs.open(path,std::fstream::in);
        if(!fs.is_open()){
                fprintf(stdout,"config file %s can't be opened",path);
                return 1;
        }
        
        std::string buf;
        int op = 0;
        repo_t * repo;
        while(!fs.eof()){
                std::getline(fs,buf);
                if(buf[0]=='#')continue;
                else if(buf[0]=='['&&buf[buf.size()-1]==']'){
                        if(buf=="[options]"){
                                free(option);
                                option = (option_t*)calloc(1,sizeof(option_t));
                                op = 1;
                        }
                        else{
                                repo = (repo_t*)calloc(1,sizeof(repo_t));
                                repos = alpm_list_add(repos,repo);
                                stchar(&repo->name,buf.substr(1,buf.size()-2));
                                op = 2;
                        }
                }
                if(op==1){
                        parseline_option(buf,option);
                }
                else if(op==2){
                        parseline_repo(buf,repo);
                }
        }
        fs.close();
}
/* configure the conf_t with option_t */
void conf_t::conf_set_option()
{
        if(option->rootdir){
                conf_set_root(option->rootdir);
        }
        if(option->dbpath){
                conf_set_dbpath(option->dbpath);
        }
        if(option->cachedirs){
                conf_set_cachedirs(string_to_list(option->cachedirs));
        }
        if(option->logfile){
                conf_set_logfile(option->logfile);
        }
        if(option->gpgdir){
                conf_set_gpgdir(option->gpgdir);
        }
        if(option->hookdir){
                conf_set_hookdir(option->hookdir);
        }
        if(option->arch){
                conf_set_arch(option->arch);
        }
        if(option->holdpkgs){
                conf_set_holdpkgs(str_split(option->holdpkgs));
        }
        if(option->ignorepkgs){
                conf_set_ignorepkgs(str_split(option->ignorepkgs));
        }
        if(option->ignoregrps){
                conf_set_ignoregrps(str_split(option->ignoregrps));
        }
        if(option->noupgrades){
                conf_set_noupgrades(str_split(option->noupgrades));
        }
        if(option->noextracts){
                conf_set_noextracts(str_split(option->noextracts));
        }
}

/* initialize the remote database */
int conf_t::conf_hd_init_syncdbs()
{
        alpm_list_t* i;
        for(i=repos;i;i=alpm_list_next(i)){
                repo_t* repo = (repo_t*)i->data;
                alpm_db_t* db = alpm_register_syncdb(handle,repo->name,ALPM_SIG_USE_DEFAULT);
                if(!db){
                        fprintf(stdout,"can't register database: %s\n",repo->name);
                        continue;
                }
                alpm_list_t* j;
                alpm_list_t* servers = nullptr;
                for(j=repo->server;j;j=alpm_list_next(j)){
                        char* oldurl = (char*)j->data;
                        char* newurl = strreplace(oldurl,REP_REPO,repo->name);
                        char* tempurl = newurl;
                        newurl = strreplace(tempurl,REP_ARCH,arch);
                        free(tempurl);
                        servers = alpm_list_add(servers,newurl);
                }
                alpm_db_set_servers(db,servers);
                if(alpm_db_get_valid(db)){
                        fprintf(stdout,"db %s invalid:%s",alpm_db_get_name(db),\
                                        alpm_strerror(alpm_errno(handle)));
                }
        }
}
conf_t::~conf_t()
{
        //alpm_release(handle);
        FREELIST(repos);
        free(option);
        free(logfile); 
        free(arch); 
        free(gpgdir); 
        free(hookdir); 
        free(conffile); 
        free(notepath); 

        FREELIST(holdpkgs);
        FREELIST(cachedirs);
        FREELIST(noextracts);
        FREELIST(noupgrades);
        FREELIST(ignorepkgs);
        FREELIST(ignoregrps);

        free(root);
        free(dbpath);
        free(lockfile);
}
