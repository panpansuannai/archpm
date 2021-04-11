/* log.hpp */
#pragma once

#include <string>

using std::string;

class Log {
public:
    Log& operator<<(string);
};

extern Log LOG;
