/* optparse.hpp */

#pragma once

#include "configure.h"
#include "database.h"
#include "option.h"

using std::shared_ptr;
using std::string;
using std::vector;
using OptionPtr = shared_ptr<Option>;

class OptParser {
public:
  enum class State { INITIALIZE, OPTIONS, DATABASE };

  OptParser(State st = State::INITIALIZE) : state_(st), db_(nullptr) {}

  void switchState(State st) { state_ = st; }
  OptionPtr parse_sentence(string);
  vector<OptionPtr> parse_file(string);

private:
  State state_;
  DataBase *db_;
  OptParser(const OptParser &) = delete;
  OptParser &operator=(const OptParser &) = delete;
};
