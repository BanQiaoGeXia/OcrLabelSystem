#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "framewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    btn_layout = new QVBoxLayout();

    select_frame_btn = new QPushButton(tr("边框标注"), this);
    select_frame_btn->setMinimumSize(100, 40);
    select_frame_btn->setMaximumSize(100, 40);

    btn_layout->addStretch();
    btn_layout->addWidget(select_frame_btn);
    btn_layout->addStretch();

    main_layout = new QHBoxLayout();
    main_layout->addStretch();
    main_layout->addLayout(btn_layout);
    main_layout->addStretch();
    QWidget *main_widget = new QWidget(this);
    main_widget->setLayout(main_layout);
    this->setCentralWidget(main_widget);

    connect(select_frame_btn, &QPushButton::clicked, this, &MainWindow::change_window);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_window()
{
    this->hide();
    frame_window = new FrameWindow();
    frame_window->show();
}
