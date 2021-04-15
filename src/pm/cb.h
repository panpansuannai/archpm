/*
 *  cb.h
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
#ifndef CB_H
#define CB_H

#include "cb.h"
#include "util.h"
#include <alpm.h>

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char *timeout_db;
extern char *timeout_pkg;
void cb_event(alpm_event_t *event);

void cb_quest(alpm_question_t *question);

void cb_prog(alpm_progress_t event, const char *pkgname, int percent,
             size_t howmany, size_t remain);

void cb_tdl(off_t total);

void cb_dl(const char *filename, off_t xfered, off_t total);

void cb_log(alpm_loglevel_t level, const char *fmt, va_list args);

int cb_fetch(const char *url, const char *localfile, int force);
#endif
