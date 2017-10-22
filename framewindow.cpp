#include "framewindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QHBoxLayout>

#include "filetreeview.h"
#include "imageview.h"

FrameWindow::FrameWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setMinimumSize(1000, 600);
    open_file_action = new QAction(tr("&Open File"), this);
    open_file_action->setStatusTip(tr("Open a file."));
    open_dir_action = new QAction(tr("&Open Directory"), this);
    open_dir_action->setStatusTip(tr("Open a Directory"));

    file = this->menuBar()->addMenu(tr("&File"));
    file->addAction(this->open_file_action);
    file->addAction(this->open_dir_action);
    tool_bar = new QToolBar;
    tool_bar->addAction(this->open_file_action);
    tool_bar->addAction(this->open_dir_action);
    this->addToolBar(tool_bar);
    connect(open_file_action, &QAction::triggered, this, &FrameWindow::show_file_dialog);
    connect(open_dir_action, &QAction::triggered, this, &FrameWindow::show_dir_dialog);


    file_tree_view = new FileTreeView;
    image_view = new ImageView;
    main_layout = new QHBoxLayout();
    main_layout->addWidget(file_tree_view);
    main_layout->addWidget(image_view);
    QWidget *main_widget = new QWidget(this);
    main_widget->setLayout(main_layout);
    this->setCentralWidget(main_widget);
}

void FrameWindow::show_file_dialog()
{
    QString file_path = QFileDialog::getOpenFileName(this);
    this->set_dir_path(file_path, 0);
}

void FrameWindow::show_dir_dialog()
{
    QString dir_path = QFileDialog::getExistingDirectory(this);
    this->set_dir_path(dir_path, 1);
}

void FrameWindow::set_dir_path(QString file_path, int index)
{
    if(index == 0)
    {
        QStringList path_list = file_path.split('/');
        this->dirPath = "";
        for(int i = 0; i < path_list.size() - 1; i ++)
        {
            this->dirPath += path_list[i];
            this->dirPath += "/";
        }
    }
    else if(index == 1)
    {
        this->dirPath = file_path;
    }
    else
    {
        this->dirPath = "";
    }
    message_box->information(this, "aa", this->dirPath, QMessageBox::Ok);
}

QString FrameWindow::get_dir_path()
{
    return this->dirPath;
}
