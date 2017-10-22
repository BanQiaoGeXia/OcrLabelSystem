#include "filetreeview.h"

#include <QStandardItemModel>
#include <QStringList>

FileTreeView::FileTreeView(QWidget *parent) : QTreeView(parent)
{
    this->setMinimumWidth(200);
    this->setMaximumWidth(200);
    dir_model = new QStandardItemModel(this);
    dir_model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("项目名")<<QStringLiteral("aaaaa"));

}
