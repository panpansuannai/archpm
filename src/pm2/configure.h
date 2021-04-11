#pragma once

#include <alpm.h>
#include <alpm_list.h>
#include <cstddef>
#include <string>
#include <vector>

#include "option.h"
#include "log.h"

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
#define DEF_NOTEPATH "/var/lib/archpm/"

#define REP_REPO "$repo" 
#define REP_ARCH "$arch" 

static void set_up_callback_func()
{
    return;
}

class Configure {

private:
    alpm_handle_t* handle_;

    Configure(const Configure&) = delete;
    Configure operator=(Configure&) = delete;

    friend void set_up_callback_func();

  public:
    using OptionPtr = std::shared_ptr<Option>;
    Configure(string root, string dbpath): handle_(nullptr) 
    {
        alpm_errno_t err ;
        handle_ = alpm_initialize(root.c_str(), dbpath.c_str(), &err);
        if(!handle_) {
            LOG << "[E] Configure: Initialize handle err :" << string(alpm_strerror(err));
            exit(0);
        }
        set_up_callback_func();
    }

    Configure() : Configure(string(DEF_ROOT), string(DEF_DBPATH)) { }

    ~Configure()  { 
        alpm_release(handle_);
    }

    bool setup_opt(OptionPtr opt) {
        return opt->do_opt(handle_);
    }
};
