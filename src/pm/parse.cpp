/*
 *  parse.cpp
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
#include <alpm.h>
#include <alpm_list.h>

#include "parse.h"
#include "conf.h"
#include "debug.h"
#include "util.h"

#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>

#define BS 1024
#define CLEN 512

alpm_list_t * pd = NULL;
static int parse_siglevel(const char* orig, alpm_siglevel_t* osig)
{
        int *sig;
        sig = (int*)osig;
        int tgt = 0;
        const char* value;
        if(strncmp(orig,"Package",strlen("Package"))==0){
                tgt = 1;
                value = orig + strlen("Package");
        }
        else if(strncmp(orig,"Database",strlen("Database"))==0){
                tgt = 2;
                value = orig + strlen("Database");
        }
        else {
                /* illegal config */
                tgt = 3;
                value = orig;
        }
        if(strncmp(value,"Never",strlen("Never"))==0){
                if(tgt >= 1){
                        *sig &= ~(ALPM_SIG_PACKAGE);
                }
                if(tgt >= 2){
                        *sig &= ~(ALPM_SIG_DATABASE);
                }
        }
        else if(strncmp(value,"Optional",strlen("Optional"))==0){
                if(tgt >= 1){
                        *sig |= ALPM_SIG_PACKAGE_OPTIONAL;
                        *sig |= ALPM_SIG_PACKAGE;
                }
                if(tgt >= 2){
                        *sig |= ALPM_SIG_DATABASE_OPTIONAL;
                        *sig |= ALPM_SIG_DATABASE;
                }
        }
        else if(strncmp(value,"Required",strlen("Required"))==0){
                if(tgt >= 1){
                        *sig |= ALPM_SIG_PACKAGE;
                        *sig &= ~(ALPM_SIG_PACKAGE_OPTIONAL);
                }
                if(tgt >= 2){
                        *sig |= ALPM_SIG_DATABASE;
                        *sig &= ~(ALPM_SIG_DATABASE_OPTIONAL);
                }
        }
        else if(strncmp(value,"TrustedOnly",strlen("TruestedOnly"))==0){
                if(tgt >= 1){
                        *sig &= ~ALPM_SIG_PACKAGE_MARGINAL_OK;
                        *sig &= ~ALPM_SIG_PACKAGE_UNKNOWN_OK;
                }
                if(tgt >= 2){
                        *sig &= ~ALPM_SIG_DATABASE_MARGINAL_OK;
                        *sig &= ~ALPM_SIG_DATABASE_UNKNOWN_OK;
                }
        }
        else if(strncmp(value,"TrustAll",strlen("TrustAll"))==0){
                if(tgt >= 1){
                        *sig |= ALPM_SIG_PACKAGE_MARGINAL_OK;
                        *sig |= ALPM_SIG_PACKAGE_UNKNOWN_OK;
                }
                if(tgt >= 2){
                        *sig |= ALPM_SIG_DATABASE_MARGINAL_OK;
                        *sig |= ALPM_SIG_DATABASE_UNKNOWN_OK;
                }

        }
        *sig &= ~ALPM_SIG_USE_DEFAULT;
        return 0;
}
/** @brief parse a singal line , and parse it like "key = value".
 * if there is a "=", return 1
 * or return 0
 * the result will be saved at key and value
 */
static int parseline(std::string& line, char** key, char** value)
{
        int ret = 1;
        size_t pos = line.find('=');
        if(pos==std::string::npos){
                ret = 0;
                stchar(key,line);
        }
        /* there is one space around the '=' */
        else {
                stchar(key,line.substr(0,pos-1));
                stchar(value,line.substr(pos+2));
        }
        return ret;
}
/* parse a singal line to configure struct option */
int parseline_option(std::string& line,option_t* option)
{
        char * key = nullptr;
        char * value = nullptr;
        if(parseline(line,&key,&value)==1){
                /* there is a '=' in line */
                if(strcmp(key,"RootDir")==0){
                        option->rootdir = value;
                }
                else if(strcmp(key, "DBPath")==0){
                        option->dbpath = value;
                }
                else if(strcmp(key, "CacheDir")==0){
                        option->cachedirs = value;
                }
                else if(strcmp(key, "LogFile")==0){
                        option->logfile = value;
                }
                else if(strcmp(key, "GPGDir")==0){
                        option->gpgdir = value;
                }
                else if(strcmp(key, "HookDir")==0){
                        option->hookdir = value;
                }
                else if(strcmp(key, "Architecture")==0){
                        if(strcmp(value,"auto")==0){
                                option->arch = strdup(DEF_ARCH);
                        }
                        else option->arch = value;
                }
                else if(strcmp(key, "HoldPkg")==0){
                        option->holdpkgs = value;                         
                }
                else if(strcmp(key, "IgnorePkg")==0){
                        option->ignorepkgs = value;
                }
                else if(strcmp(key, "IgnoreGroup")==0){
                        option->ignoregrps = value;
                }
                else if(strcmp(key, "NoUpgrade")==0){
                        option->noupgrades = value;
                }
                else if(strcmp(key, "NoExtract")==0){
                        option->noextracts = value;
                }
                else if(strcmp(key, "UseSyslog")==0){
                        option->usesyslog = 1;
                }
                else if(strcmp(key, "CheckSpace")==0){
                        option->checkspace =1;
                }
                else if(strcmp(key, "SigLevel")==0){
                        parse_siglevel(value,&option->siglevel);
                }

                free(key);
        }
        return 0;
        
}
/** @brief parse the server with the file 
 * @param file indicate the targe file
 * @param repo indicate the targe repo
 */
static int parse_include(char* file,repo_t* repo)
{
        if(!check_file(file)){
                fprintf(stderr,"In conf.cpp:139: parse_include error: %s doesn't exists\n",file);
                return 1;
        }
        std::ifstream sfile(file);
        if(!sfile.is_open()){
                fprintf(stderr,"In conf.cpp:145: parse_include error: %s doesn't exists\n",file);
                return 1;
        }
        std::string buf;
        while(getline(sfile,buf)){
                if(buf.empty()||buf[0]=='#')
                        continue;
                else {
                        char *key;
                        char *value;
                        if(parseline(buf,&key,&value)==1){
                                if(strcmp(key,"Server")==0){
                                        repo->server = alpm_list_add(repo->server,value); 
                                }
                                else{
                                        free(value);
                                }
                                free(key);
                        }
                }
        }
        sfile.close();
        return 0;
        
}

/* parse a singal line to configure struct repo */
int parseline_repo(std::string& line, repo_t* repo)
{
        char *key;
        char *value;
        if(parseline(line,&key,&value)==1){
                
                if(strcmp(key, "SigLevel")==0){
                        parse_siglevel(value,&repo->siglevel);
                }
                else if(strcmp(key, "Server")==0){
                        repo->server = alpm_list_add(repo->server,value);
                }
                else if(strcmp(key, "Include")==0){
                        alpm_list_t* i;
                        int flag = 0;
                        parsed* p;
                        for(i=pd;i;i=alpm_list_next(i)){
                                p = (parsed*)i->data;
                                if(strcmp(value,p->file)==0){
                                        flag = 1;
                                        break;
                                }
                        }
                        if(flag){
                                repo->server = p->server;
                        }
                        else {
                                parsed *p = (parsed*)calloc(1,sizeof(parsed));
                                p->file = strdup(value);
                                parse_include(value,repo);
                                p->server = repo->server;
                                pd = alpm_list_add(pd,p);
                        }
                }
                free(key);
        }
        return 0;
        
}
