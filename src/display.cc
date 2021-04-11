#include "display.h"
#include "entry.h"
#include "mainwindow.h"
#include "dialog.h"
#include <QWidget>
#include <QLabel>

static int get_pagenum(QComboBox* com)
{
        return 1<<(com->currentIndex()+4);
}
display::display(QVBoxLayout* layout,operation* opera,QComboBox* num,QLabel* m,QObject* parent)
    :QObject(parent),dis(layout),combo(num),op(opera),msg(m)
{
        curIndex = 0;
        itemnum = get_pagenum(combo);

}
int display::add_entries(alpm_list_t* pkgs)
{

        if(!pkgs)return 0;
        int num = 0;
        for(;pkgs;pkgs = alpm_list_next(pkgs)){ 
                alpm_pkg_t* pkg = (alpm_pkg_t*)pkgs->data;
                add_entry(pkg);
                num++;
        }
        slot_next_page();
        return num;
}
int display::add_entry(alpm_pkg_t* pkg)
{

        waitList.push_back(pkg);
        return 0;
}

int display::cleanup()
{
        cleanup_entries();
        while(waitList.size()>0){
                waitList.pop_back();
        }
        curIndex = 0;
}

display::~display()
{

}

/*-----------------@SLOT FUNCTION-------------------*/
void display::slot_remove_entry(entry* ent)
{
        for(auto it=entries.begin();it!=entries.end();++it){
                if(ent == *it){
                        entries.erase(it);
                        ent->~entry();
                        return;
                }
        }
}

void display::slot_install_entry()
{

}

void display::slot_next_page()
{
        if(curIndex>=waitList.size()){
                msg->setText("This is the last page.");
                return;
        }
        cleanup_entries();
        itemnum  = get_pagenum(combo);
        int i = 0;
        for(i=0;(i<itemnum)&&(curIndex+i<waitList.size());++i){
                alpm_pkg_t* pkg  = waitList[curIndex+i];
                if(pkg==nullptr)continue;
                entry *ent = new entry(pkg,op);
                this->dis->addWidget(ent);
                /* when remove entry */
                connect(ent,SIGNAL(sig_remove_pkg(entry*)),this,SLOT(slot_remove_entry(entry*)));
                /* when install entry */
                connect(ent,SIGNAL(sig_install_pkg()),this,SLOT(slot_install_entry()));
                entries.push_back(ent);
        }
        curIndex += i;
}
void display::slot_prev_page()
{
        itemnum = get_pagenum(combo);
        if(curIndex-itemnum<=0){
                msg->setText("This is the first page.");
                return;
        }
        int i=0;
        if(curIndex-2*itemnum>i)i=curIndex-2*itemnum;
        curIndex -= itemnum;
        cleanup_entries();
        for(;i<curIndex;++i){
                alpm_pkg_t* pkg  = waitList[i];
                if(pkg==nullptr)continue;
                entry *ent = new entry(pkg,op);
                this->dis->addWidget(ent);
                entries.push_back(ent);
                /* when remove entry */
                connect(ent,SIGNAL(sig_remove_pkg(entry*)),this,SLOT(slot_remove_entry(entry*)));
                /* when install entry */
                connect(ent,SIGNAL(sig_install_pkg()),this,SLOT(slot_install_entry()));
                
        }
}

void display::cleanup_entries()
{
        for(entry* i: this->entries){
            delete i;
        }
        entries.clear();
}

alpm_list_t* display::install_page()
{
        alpm_list_t* pkgs = nullptr;
        for(entry* ent : entries){
                pkgs = alpm_list_add(pkgs,ent->package);
        }
        op->install_list(pkgs);
        alpm_list_t* ret = op->check_installed(pkgs);
        return ret;
}
alpm_list_t* display::remove_page()
{
        alpm_list_t* ret = nullptr;
        for(entry* ent : entries){
                if(!op->remove(ent->package)){
                        ret = alpm_list_add(ret,ent->package);
                }
        }
        return ret;
        
}
