/* option.cc */

#include <cstring>

#include "option.h"

static std::vector<string>* __split_item(string str)
{
    std::vector<string>* items = new std::vector<string>();
    size_t lp = 0;
    size_t pos = 0;
    bool start = false;
    while (pos < str.size()){
        if(!start&&isalpha(str[pos])){
            lp = pos;
            start = true;
        }
        if(start && (pos == str.size() - 1 || str[pos+1] == ' ')){
            start = false;
            items->push_back(str.substr(lp,pos-lp+1));
        }
        pos ++;
    }
    return items;
}
ListOption::ListOption(string str)
{
    std::vector<string>* items = __split_item(str);
    for(string& i : *items){
        char* _str = (char*)malloc(i.size());
        strncpy(_str,i.c_str(),i.size());
        this->add_item(_str);
    }
    delete items;
}
