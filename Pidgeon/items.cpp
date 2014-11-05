//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#include "items.h"
#include "window.h"
#include "ui_items.h"

using namespace pidgeon;

Items *Items::List = NULL;

Items::Items(QWidget *parent) : QDialog(parent), ui(new Ui::Items)
{
    this->ui->setupUi(this);
    this->Model = new QStandardItemModel();
    this->Root = this->Model->invisibleRootItem();
    this->SystemWindow = new QStandardItem("System");
    this->Root->appendRow(this->SystemWindow);
    this->ui->treeView->setModel(this->Model);
    this->ui->treeView->header()->hide();
    this->ui->treeView->expandAll();
    this->db.insert(this->SystemWindow, Window::MainWindow->Root);
}

Items::~Items()
{
    delete this->ui;
}

void Items::Open(const QModelIndex &index)
{
    if (this->db.contains(this->Model->itemFromIndex(index)))
        Window::MainWindow->SwitchChat(db[this->Model->itemFromIndex(index)]);
}

void Items::Refresh()
{

}

void pidgeon::Items::on_pushButton_clicked()
{
    this->hide();
}

void pidgeon::Items::on_treeView_activated(const QModelIndex &index)
{
    this->Open(index);
}

void pidgeon::Items::on_treeView_clicked(const QModelIndex &index)
{
    this->Open(index);
}
