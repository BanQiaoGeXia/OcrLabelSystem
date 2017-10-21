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
    open_action = new QAction(tr("&Open"), this);
    open_action->setShortcut(QKeySequence::Open);
    open_action->setStatusTip(tr("Open a file."));
    file = this->menuBar()->addMenu(tr("&File"));
    file->addAction(this->open_action);
    tool_bar = new QToolBar;
    tool_bar->addAction(this->open_action);
    this->addToolBar(tool_bar);
    connect(open_action, &QAction::triggered, this, &FrameWindow::show_file_dialog);

}

void FrameWindow::InitEvent()
{
//    connect(open_action, &QAction::triggered, this, &FrameWindow::show_file_dialog);
}

void FrameWindow::show_file_dialog()
{
//    file_dialog = new QFileDialog(this);
//    file_dialog->exec();
//    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Text Files(*.txt)"));

    QString fileName = QFileDialog::getOpenFileName(this);    //得到文件名
    message_box->information(this, "aa", fileName, QMessageBox::Ok);
}
