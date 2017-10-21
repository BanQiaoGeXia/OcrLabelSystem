#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class FrameWindow;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void change_window();

private:
    Ui::MainWindow *ui;

    FrameWindow *frame_window;

    QPushButton *select_frame_btn;

    QHBoxLayout *main_layout;
    QVBoxLayout *btn_layout;

};

#endif // MAINWINDOW_H
