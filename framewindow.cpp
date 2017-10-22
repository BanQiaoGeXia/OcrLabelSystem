#include "framewindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QString>

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
}

void FrameWindow::InitEvent()
{
//    connect(open_action, &QAction::triggered, this, &FrameWindow::show_file_dialog);
}

void FrameWindow::show_file_dialog()
{
    QString file_path = QFileDialog::getOpenFileName(this);
    message_box->information(this, "file", file_path, QMessageBox::Ok);
}

void FrameWindow::show_dir_dialog()
{
    QString dir_path = QFileDialog::getExistingDirectory(this);
    message_box->information(this, "dir", dir_path, QMessageBox::Ok);
}

void FrameWindow::set_file_path(QString file_path)
{
    filePath = file_path;
}

QString FrameWindow::get_file_path()
{
    return filePath;
}
