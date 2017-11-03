#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "shape.h"

namespace Ui {
class MainWindow;
}

class ImageWidget;
class QScrollArea;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void open();
    void about();

signals:
    void changeCurrentShape(Shape::Code newShape);

private slots:
    void drawMKPointActionTriggered();

private:
    void InitActions();

    //重新加载图片窗口
    void ReloadImageWidget(QString path);

private:
    Ui::MainWindow *ui;
    QString selectPath;
    QScrollArea *scrollArea;
    ImageWidget *imageWidget;
    QAction *drawMKPointAction;
    QAction *turnBackAction;
    QAction *deleteShapesAction;
};

#endif // MAINWINDOW_H
