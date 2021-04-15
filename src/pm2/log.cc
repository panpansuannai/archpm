/* log.cc */

#include <iostream>
#include <string>

#include "log.h"

Log LOG;

Log &Log::operator<<(string str) {
#ifdef STD_LOG
  std::cout << str;
#endif
  return *this;
}
