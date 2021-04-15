/*
 *  util.h
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
#ifndef UTIL_H
#define UTIL_H

#include <alpm.h>
#include <string>

void stchar(char **, std::string);

int check_uid();

void clean_up(void);

void clean_sig(alpm_handle_t *);

bool check_file(const char *);

alpm_list_t *copy_pkgs_name(alpm_list_t *);

void free_list_char(alpm_list_t *);

alpm_list_t *string_to_list(const char *);
alpm_list_t *str_split(const char *);

int rm_file(const char *path);

char *get_size(int);

char *strreplace(const char *, const char *, const char *);
#endif
