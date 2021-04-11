/* option.hpp */

#pragma once

#include <alpm.h>
#include <alpm_list.h>

#include <vector>
#include <string>
#include <cstring>
#include <memory>

using std::string;

#define     OPTID   0
class Option{
public:
    using OptionPtr = std::shared_ptr<Option*>;
    virtual bool do_opt(alpm_handle_t*) = 0;
    virtual int get_id() = 0 ;
};

/*------------- list options --------------*/
class ListOption: public Option{
protected:
    alpm_list_t* list_;
public:
    ListOption(string str);
    ListOption():
        list_(nullptr) { }
    virtual bool do_opt(alpm_handle_t*) = 0;
    virtual alpm_list_t* getList(){
        return list_;
    }
    virtual bool add_item(void* pointer){
        alpm_list_add(list_,pointer);
        return true;
    }
    virtual ~ListOption(){

    }
};

#define     OPTID_HOOK     0x1 
class HookDirsOpt: public ListOption{
public:
    explicit HookDirsOpt(string str):
        ListOption(str) { }
    HookDirsOpt():
        ListOption() { }

    virtual bool do_opt(alpm_handle_t* handle) override{
        alpm_option_set_hookdirs(handle,list_);
        return true;
    }
    virtual int get_id() override { return OPTID_HOOK; }
};

#define     OPTID_CACHE     0x2
class CacheDirsOpt: public ListOption{
public:
    explicit CacheDirsOpt(string str):
        ListOption(str) { }
    CacheDirsOpt():
        ListOption() { }

    virtual bool do_opt(alpm_handle_t* handle) override{
        alpm_option_set_cachedirs(handle,list_);
        return true;
    }
    virtual int get_id() override { return OPTID_CACHE; }
};

#define     OPTID_NOEXT     0x4
class NoExtractsOpt: public ListOption{
public:
    explicit NoExtractsOpt(string str):
        ListOption(str) { }
    NoExtractsOpt():
        ListOption() { }

    virtual bool do_opt(alpm_handle_t* handle) override{
        alpm_option_set_noextracts(handle,list_);
        return true;
    }
    virtual int get_id() override { return OPTID_NOEXT; }
};

#define     OPTID_NOUPDATE  0x8
class NoUpgradesOpt: public ListOption{
public:
    explicit NoUpgradesOpt(string str):
        ListOption(str) { }
    NoUpgradesOpt():
        ListOption() { }

    virtual bool do_opt(alpm_handle_t* handle) override{
        alpm_option_set_noupgrades(handle,list_);
        return true;
    }
    virtual int get_id() override { return OPTID_NOUPDATE; }
};

#define     OPTID_IGPKG     0x10
class IgnorePkgsOpt: public ListOption{
public:
    explicit IgnorePkgsOpt(string str):
        ListOption(str) { }
    IgnorePkgsOpt():
        ListOption() { }

    virtual bool do_opt(alpm_handle_t* handle) override{
        alpm_option_set_ignorepkgs(handle,list_);
        return true;
    }
    virtual int get_id() override { return OPTID_IGPKG; }
};

#define     OPTID_IGGRP     0x20
class IgnoreGrpOpt: public ListOption{
public:
    explicit IgnoreGrpOpt(string str):
        ListOption(str) { }
    IgnoreGrpOpt():
        ListOption() { }
    virtual bool do_opt(alpm_handle_t* handle) override{
        alpm_option_set_ignoregroups(handle,list_);
        return true;
    }
    virtual int get_id() override { return OPTID_IGGRP; }
};

/*------------- string options --------------*/

class StrOption: public Option{
protected:
    string value_;
public:
    StrOption(string str): value_(str) { }

    string get_value(){
        return value_;
    }
    virtual bool do_opt(alpm_handle_t*) override {
        return true;
    }
    virtual int get_id() override{
        return OPTID;
    }
    virtual ~StrOption() { }

};

#define     OPTID_NAME      0x40
class NameOpt:public StrOption{
public:
    explicit NameOpt(string str):
        StrOption(str) { }

    virtual bool do_opt(alpm_handle_t* handle) override{
        return true;
    }
    virtual int get_id() override { return OPTID_NAME; }
    ~NameOpt() { }
};

#define     OPTID_LOG       0x80
class LogFileOpt:public StrOption{
public:
    explicit LogFileOpt(string str):
        StrOption(str) { }

    virtual bool do_opt(alpm_handle_t* handle) override{
        char* _str = (char*)malloc(value_.size());
        strncpy(_str, value_.c_str(), value_.size());
        alpm_option_set_logfile(handle, _str);
        return true;
    }
    virtual int get_id() override { return OPTID_LOG; }

     ~LogFileOpt() { }
};

#define     OPTID_ARCH      0x100
class ArchOpt:public StrOption{
public:
    explicit ArchOpt(string str):
        StrOption(str) { }
    virtual bool do_opt(alpm_handle_t* handle) override{
        char* _str = (char*)malloc(value_.size());
        strncpy(_str, value_.c_str(), value_.size());
        alpm_option_set_arch(handle, _str);
        return true;
    }
    virtual int get_id() override { return OPTID_ARCH; }
    ~ArchOpt() { }
};

#define     OPTID_GPG       0x200
class GPGDirOpt:public StrOption{
public:
    explicit GPGDirOpt(string str):
        StrOption(str) { }
    virtual bool do_opt(alpm_handle_t* handle) override{
        char* _str = (char*)malloc(value_.size());
        strncpy(_str, value_.c_str(), value_.size());
        alpm_option_set_gpgdir(handle,_str);
        return true;
    }
    virtual int get_id() override { return OPTID_GPG; }
    ~GPGDirOpt() { }
};

#define     OPTID_NOTE      0x400
class NoteOpt:public StrOption{
public:
    explicit NoteOpt(string str):
        StrOption(str) { }
    virtual bool do_opt(alpm_handle_t* handle) override{
        //TODO
        return true;
    }
    virtual int get_id() override { return OPTID_NOTE; }
    ~NoteOpt() { }
};

#define     OPTID_ROOT      0x800
class RootDirOpt: public StrOption {
public:
    explicit RootDirOpt(string str):
        StrOption(str) { }
    virtual bool do_opt(alpm_handle_t* handle) override{
        return true;
    }
    virtual int get_id() override { return OPTID_ROOT; }
    ~RootDirOpt() { }
};

#define     OPTID_DBPATH    0x1000
class DBPathOpt: public StrOption {
public:
    explicit DBPathOpt(string str):
        StrOption(str) { }
    virtual bool do_opt(alpm_handle_t* handle) override{
        return true;
    }
    virtual int get_id() override { return OPTID_DBPATH; }
    ~DBPathOpt() { }
};


