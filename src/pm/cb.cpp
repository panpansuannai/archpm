/*
 *  cb.b
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
#include "cb.h"
#include "util.h"
#include <alpm.h>

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *timeout_db = strdup("10");
char *timeout_pkg = strdup("60");
void cb_event(alpm_event_t *event) {
  fprintf(stdout, "**cb_event called!\n\n");
}

void cb_quest(alpm_question_t *question) {
  fprintf(stdout, "**cb_quest called!\n\n");
}

void cb_prog(alpm_progress_t event, const char *pkgname, int percent,
             size_t howmany, size_t remain) {
  // fprintf(stdout,"**cb_prog called!\npkgname:%s\npercent:%d\nhowmany:%d\n");
}

void cb_tdl(off_t total) { fprintf(stdout, "**cb_tdl called!\n\n"); }

void cb_dl(const char *filename, off_t xfered, off_t total) {
  fprintf(stdout, "**cb_dl called! %d\n\n", xfered);
}

void cb_log(alpm_loglevel_t level, const char *fmt, va_list args) {}
static char *combine_path(const char *url, const char *localfile) {
  char *ret = (char *)calloc(1, sizeof(char) * 512);
  const char *find = url;
  while (*find != '\0')
    find++;
  while (*find != '/')
    find--;
  strcat(ret, localfile);
  strcat(ret, find + 1);
  return ret;
}

int cb_fetch(const char *url, const char *localfile, int force) {
  char *path = combine_path(url, localfile);
  const char *db = strstr(url, "db");

  int pid = fork();
  if (pid == 0) {
    if (db) {
      execl("/usr/bin/wget", "wget", url, "-t", "1", "-T", timeout_db, "-O",
            path, NULL);
    } else {
      execl("/usr/bin/wget", "wget", url, "-t", "1", "-T", timeout_pkg, "-O",
            path, NULL);
    }
    // execl("/usr/bin/curl","curl",url,"--output",path,NULL);
  } else {
    waitpid(-1, NULL, NULL);
    free(path);
  }
  return 0;
}
