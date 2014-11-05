//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#ifndef ITEMS_H
#define ITEMS_H

#include <QDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QHash>

namespace Ui
{
    class Items;
}

namespace pidgeon
{
    class ChatBox;
    class Items : public QDialog
    {
            Q_OBJECT
        public:
            static Items *List;
            explicit Items(QWidget *parent = 0);
            ~Items();
            void Open(const QModelIndex &index);
            void Refresh();
            QStandardItem *SystemWindow;
            QHash<QStandardItem*, ChatBox*> db;
            QStandardItemModel *Model;

        private slots:
            void on_pushButton_clicked();
            void on_treeView_activated(const QModelIndex &index);

            void on_treeView_clicked(const QModelIndex &index);

        private:
            QStandardItem *Root;
            Ui::Items *ui;
    };
}

#endif // ITEMS_H
