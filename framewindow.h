#ifndef FRAMEWINDOW_H
#define FRAMEWINDOW_H

#include <QMainWindow>

class QMenu;
class QMenuBar;
class QAction;
class QToolBar;
class QMessageBox;
class QFileDialog;

class FrameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit FrameWindow(QWidget *parent = 0);

    void InitEvent();
signals:

public slots:
    void show_file_dialog();

private:
    QAction *open_action;
    QMenu *file;
    QToolBar *tool_bar;
    QMessageBox *message_box;
    QFileDialog *file_dialog;
};

#endif // FRAMEWINDOW_H
