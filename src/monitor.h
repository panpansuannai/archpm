/*
 *  Mointor.h *
 *  Copyright (c) 2020- panpansuannai <panpansuannai@outlook.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include <functional>
#include <queue>
#include <vector>

#include "pkg_entry.h"
#include "pm2/package.h"

/* only operate on Monitor::wait_queue */
#define __ONLY_QUEUE
/* only operate on Monitor::view */
#define __ONLY_VIEW
/* Both wait_queue and view are operated */
#define __BOTH_QUEUE_VIEW

class PkgEntry;

class Monitor : public QObject {
  Q_OBJECT
public:
  using PackagePtr = Package::PackagePtr;
  using PkgEntryPtr = std::shared_ptr<PkgEntry>;

  explicit Monitor(QVBoxLayout *, QComboBox *, QLabel *);

  void push_queue __ONLY_QUEUE(Package::PackagePtr);
  // sort the package in queue
  void sort_queue __ONLY_QUEUE(std::function<bool(PackagePtr, PackagePtr)>);
  ~Monitor();

public slots:
  void change_items_per_page();
  void clear_queue __BOTH_QUEUE_VIEW();
  void clear_view __ONLY_VIEW();
  void filter_queue __ONLY_QUEUE(std::function<bool(PackagePtr)>);
  void filter_view __ONLY_VIEW(std::function<bool(PkgEntryPtr)>);
  void next_page __ONLY_VIEW();
  void prev_page __ONLY_VIEW();

private:
  std::vector<PackagePtr> wait_queue_;
  std::vector<PkgEntryPtr> view_;

  QComboBox *combo_;
  QVBoxLayout *layout_;
  QLabel *msg_;

  size_t cur_page_index_;
  size_t items_per_page_;
};
