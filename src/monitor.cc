#include <QLabel>
#include <QWidget>

#include <algorithm>

#include "dialog.h"
#include "monitor.h"
#include "pkg_entry.h"

static int get_page_number(QComboBox *com) {
  return com->currentText().toInt();
}

Monitor::Monitor(QVBoxLayout *layout, QComboBox *num, QLabel *m)
    : layout_(layout), combo_(num), msg_(m), cur_page_index_(0),
      items_per_page_(get_page_number(combo_)), wait_queue_(), view_() {}

void Monitor::push_queue(PackagePtr package) { wait_queue_.push_back(package); }

Monitor::~Monitor() {}

/*-----------------@SLOT FUNCTION-------------------*/
void Monitor::clear_queue() {
  view_.clear();
  wait_queue_.clear();
}

void Monitor::clear_view() { view_.clear(); }

void Monitor::filter_queue(std::function<bool(PackagePtr)> filter) {
  for (auto iterator = begin(wait_queue_); iterator != end(wait_queue_);) {
    if (!filter(*iterator)) {
      iterator = wait_queue_.erase(iterator);
    } else
      ++iterator;
  }
}

void Monitor::filter_view(std::function<bool(PkgEntryPtr)> filter) {
  for (auto iterator = begin(view_); iterator != end(view_);) {
    if (!filter(*iterator)) {
      iterator = view_.erase(iterator);
    } else
      ++iterator;
  }
}

void Monitor::change_items_per_page() {
  items_per_page_ = get_page_number(combo_);
}

void Monitor::next_page() {
  clear_view();
  size_t i = 0;
  for (; i < items_per_page_ && cur_page_index_ + i < wait_queue_.size(); ++i) {
    PkgEntryPtr pkg_entry_ptr =
        std::make_shared<PkgEntry>(wait_queue_[cur_page_index_ + i]);
    view_.push_back(pkg_entry_ptr);
  }
  cur_page_index_ += i;
}

void Monitor::prev_page() {
  cur_page_index_ -= view_.size();
  clear_view();
  size_t i =
      cur_page_index_ > items_per_page_ ? cur_page_index_ - items_per_page_ : 0;
  for (; i < cur_page_index_; ++i) {
    PkgEntryPtr pkg_entry_ptr = std::make_shared<PkgEntry>(wait_queue_[i]);
    view_.push_back(pkg_entry_ptr);
  }
}
