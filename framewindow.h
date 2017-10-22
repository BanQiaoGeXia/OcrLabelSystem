#ifndef FRAMEWINDOW_H
#define FRAMEWINDOW_H

#include <QMainWindow>

class QMenu;
class QMenuBar;
class QAction;
class QToolBar;
class QMessageBox;
class QFileDialog;
class QString;

class FrameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit FrameWindow(QWidget *parent = 0);

    void InitEvent();

    void set_file_path(QString file_path);

    QString get_file_path();
signals:

public slots:
    void show_file_dialog();
    void show_dir_dialog();

private:
    QAction *open_file_action;
    QAction *open_dir_action;
    QMenu *file;
    QToolBar *tool_bar;
    QMessageBox *message_box;
    QFileDialog *file_dialog;

    QString filePath;
};

#endif // FRAMEWINDOW_H
