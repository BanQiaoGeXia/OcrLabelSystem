#include "imagewidget.h"

#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include "mkpoint.h"

ImageWidget::ImageWidget(const QString &imagePath, QWidget *parent): QWidget(parent)
{
    QPixmap backgroundImage = QPixmap(imagePath);
    this->setMinimumSize(backgroundImage.size());
    this->setMaximumSize(backgroundImage.size());

    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(backgroundImage));
    this->setPalette(palette);
}

void ImageWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(shapeList.size()) {
        foreach(Shape * shape, shapeList) {
            shape->paint(painter);
        }
        if(shape) {
            shape->paint(painter);
        }
    }
}

void ImageWidget::mousePressEvent(QMouseEvent *e)
{
    switch(currShapeCode)
    {
    case Shape::MKPoint:{
            shape = new MKPoint;
            break;
        }
    }
    if(shape != NULL) {
        perm = false;
        shapeList<<shape;
        shape->setStart(e->pos());
        shape->setEnd(e->pos());
        update();
    }
}

void ImageWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(shape && !perm) {
        shape->setEnd(e->pos());
        update();
    }
}

void ImageWidget::mouseReleaseEvent(QMouseEvent *e)
{
    perm = true;
}

void ImageWidget::deleteLastShape()
{
    if(shapeList.size())
    {
        shapeList.pop_back();
        update();
    }
}

void ImageWidget::deleteAllShape()
{
    shapeList.clear();
    update();
}
