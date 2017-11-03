#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include <QScrollArea>
#include <QFileDialog>
#include <QStandardPaths>
#include "imagewidget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitActions();
    //创建QSCrollArea
    scrollArea = new QScrollArea;
    //创建主界面
    imageWidget = new ImageWidget("");

    //主界面加入QSCrollArea
    scrollArea->setWidget(imageWidget);

    this->setCentralWidget(scrollArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *openAct = fileMenu->addAction(tr("&Open..."), this, &MainWindow::open);
    openAct->setShortcut(QKeySequence::Open);
    fileMenu->addSeparator();
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    helpMenu->addAction(tr("About &Qt"), &QApplication::aboutQt);

    QToolBar *bar = this->addToolBar("Tools");
    QActionGroup *group = new QActionGroup(bar);

    drawMKPointAction = new QAction("point", bar);
    drawMKPointAction->setToolTip(tr("Deaw MK point"));
    drawMKPointAction->setStatusTip(tr("Deaw MK point"));
    drawMKPointAction->setCheckable(true);
    drawMKPointAction->setChecked(true);
    group->addAction(drawMKPointAction);
    bar->addAction(drawMKPointAction);

    turnBackAction = new QAction("back", bar);
    turnBackAction->setToolTip(tr("back"));
    turnBackAction->setStatusTip(tr("back"));
    group->addAction(turnBackAction);
    bar->addAction(turnBackAction);

    deleteShapesAction = new QAction("clear", bar);
    deleteShapesAction->setToolTip(tr("clear"));
    deleteShapesAction->setStatusTip(tr("clear"));
    group->addAction(deleteShapesAction);
    bar->addAction(deleteShapesAction);
}

void MainWindow::ReloadImageWidget(QString path)
{
    delete this->imageWidget;
    imageWidget = new ImageWidget(path);
    scrollArea->setWidget(imageWidget);
    connect(drawMKPointAction, SIGNAL(triggered()),
                    this, SLOT(drawMKPointActionTriggered()));

    connect(turnBackAction, SIGNAL(triggered()),
                    imageWidget, SLOT(deleteLastShape()));

    connect(deleteShapesAction, SIGNAL(triggered()),
                    imageWidget, SLOT(deleteAllShape()));
    connect(this, SIGNAL(changeCurrentShape(Shape::Code)),
                    imageWidget, SLOT(setCurrentShape(Shape::Code)));
}

void MainWindow::open()
{
    QFileDialog *fileDialog = new QFileDialog(this);
//    fileDialog->setDirectory("C:\\Users\\sunjunpeng@ucredit.com\\Desktop\\测试数据");
    if(fileDialog->exec() == QDialog::Accepted)
    {
        selectPath = fileDialog->selectedFiles()[0];
        ReloadImageWidget(selectPath);
    }
}

void MainWindow::about()
{

}

void MainWindow::drawMKPointActionTriggered()
{
    emit changeCurrentShape(Shape::MKPoint);
}
