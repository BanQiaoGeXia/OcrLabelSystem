#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "shape.h"

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(const QString &imagePath, QWidget*parent = 0);

signals:

public slots:
    void deleteLastShape();
    void deleteAllShape();

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    Shape::Code currShapeCode;
    Shape *shape;
    bool perm;
    QList<Shape*> shapeList;
};

#endif // IMAGEWIDGET_H
