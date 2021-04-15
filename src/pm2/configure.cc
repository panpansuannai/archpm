/* configure.cc */

#include <alpm.h>
#include <alpm_list.h>

#include "configure.h"
#include "log.h"
#include "option.h"

string Configure::get_hold_packages() { return string(); }

string Configure::get_ignore_packages() { return string(); }

string Configure::get_ignore_groups() { return string(); }

string Configure::get_no_extracts() { return string(); }

string Configure::get_no_upgrades() { return string(); }

string Configure::get_hook_directory() { return string(); }

string Configure::get_cache_directory() { return string(); }
