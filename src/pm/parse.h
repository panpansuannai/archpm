/*
 *  parse.h
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
#ifndef PARSE_H
#define PARSE_H

#include <alpm.h>
#include <alpm_list.h>

#include <string>

#include "conf.h"


/* save the include files
 * that have been parsed 
 * to save the time
 */
struct parsed {
        char * file;
        alpm_list_t * server;
};
extern alpm_list_t * pd;

void stchar(char**, std::string);

int parseline_option(std::string&, option_t* );

int parseline_repo(std::string&,repo_t*);

#endif
