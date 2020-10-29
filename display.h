/*
 *  display.h *
 *  Copyright (c) 2020- panpansuannai <panpansuannai@outlook.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <QVBoxLayout>
#include <QComboBox>
#include <QWidget>
#include <QLabel>
#include <vector>
#include <queue>
#include "entry.h"
#include "pm/interface.h"

class display : public QObject
{
        Q_OBJECT
public:
        QVBoxLayout* dis;
        explicit display(QVBoxLayout*,operation*,QComboBox*,QLabel*,QObject* parent=nullptr);
        QComboBox* combo;
        QLabel* msg;
        int curIndex;
        int itemnum;
        operation* op;
        ~display();


        std::vector<alpm_pkg_t*> waitList;
        std::vector<entry*> entries;

        int add_entry(alpm_pkg_t*);
        int cleanup();
        int add_entries(alpm_list_t*);
        alpm_list_t* install_page();
        alpm_list_t* remove_page();


public slots:
        void slot_remove_entry(entry*);
        void slot_install_entry();
        void slot_next_page();
        void slot_prev_page();
private:
        void cleanup_entries();
};
#endif //DISPLAY_H
