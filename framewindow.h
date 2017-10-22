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
class QHBoxLayout;

class FileTreeView;
class ImageView;

class FrameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit FrameWindow(QWidget *parent = 0);

    void set_dir_path(QString file_path, int index);

    QString get_dir_path();
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

    QHBoxLayout *main_layout;

    QString dirPath = NULL;
    FileTreeView *file_tree_view;
    ImageView *image_view;
};

#endif // FRAMEWINDOW_H
