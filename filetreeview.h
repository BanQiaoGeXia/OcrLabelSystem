#ifndef FILETREEVIEW_H
#define FILETREEVIEW_H

#include <QTreeView>

class QStandardItemModel;

class FileTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit FileTreeView(QWidget *parent = 0);

signals:

public slots:

private:

    QStandardItemModel *dir_model;
};

#endif // FILETREEVIEW_H
