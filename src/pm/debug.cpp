/*
 *  debug.h
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
#include "debug.h"
#include "conf.h"

#include <cstdio>

void debug(std::string s) { fprintf(stdout, (s + '\n').c_str()); }

void debug_db(alpm_db_t *db) {
  fprintf(stdout, "db->name:%s\n", alpm_db_get_name(db));
  fprintf(stdout, "db->siglevel:%d\n", alpm_db_get_siglevel(db));
  fprintf(stdout, "db->valid:%d\n", alpm_db_get_valid(db));
  fprintf(stdout, "debug servers\n");
  alpm_list_t *servers;
  servers = alpm_db_get_servers(db);
  for (; servers; servers = alpm_list_next(servers)) {
    fprintf(stdout, "server name: %s\n", (char *)servers->data);
  }
}

/* to printf out the member variable to debug */
void debug_conf(conf_t *conf) {
  fprintf(stdout, "conf->conffile:%s\n", conf->conffile);
  fprintf(stdout, "conf->root:%s\n", conf->root);
  fprintf(stdout, "conf->dbpath:%s\n", conf->dbpath);
  fprintf(stdout, "conf->logfile:%s\n", conf->logfile);
  fprintf(stdout, "conf->gpgdir:%s\n", conf->gpgdir);
  fprintf(stdout, "conf->arch:%s\n", conf->arch);
  fprintf(stdout, "conf->siglevel:%d\n", conf->siglevel);
}
/* to printf out the member variable in handle to debug */
void debug_handle(conf_t *conf) {
  fprintf(stdout, "handle->root:%s\n", alpm_option_get_root(conf->handle));
  fprintf(stdout, "handle->dbpath:%s\n", alpm_option_get_dbpath(conf->handle));
  fprintf(stdout, "handle->lockfile:%s\n",
          alpm_option_get_lockfile(conf->handle));
  fprintf(stdout, "handle->logfile:%s\n",
          alpm_option_get_logfile(conf->handle));
  fprintf(stdout, "handle->gpgdir:%s\n", alpm_option_get_gpgdir(conf->handle));
  fprintf(stdout, "handle->usesyslog:%d\n",
          alpm_option_get_usesyslog(conf->handle));
  fprintf(stdout, "handle->arch:%s\n", alpm_option_get_arch(conf->handle));
  fprintf(stdout, "handle->siglevel:%d\n",
          alpm_option_get_default_siglevel(conf->handle));
}
