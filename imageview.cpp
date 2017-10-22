#include "imageview.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QScrollArea>
#include <QImageReader>

ImageView::ImageView(QWidget *parent) : QWidget(parent)
{
    image_label = new QLabel();
    image_label->setBackgroundRole(QPalette::Base);
    image_label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    image_label->setScaledContents(true);

    main_layout = new QVBoxLayout(this);
    main_layout->addWidget(image_label);

    btn_prev = new QPushButton("上一张");
    btn_next = new QPushButton("下一张");

    QSpacerItem* item_left = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem* item_right = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    tool_layout = new QHBoxLayout();
    tool_layout->addSpacerItem(item_left);
    tool_layout->addWidget(btn_prev);
    tool_layout->addWidget(btn_next);
    tool_layout->addSpacerItem(item_right);

    main_layout->addLayout(tool_layout);

    this->setLayout(main_layout);
    this->setStyleSheet("background-color: rgb(167, 175, 159);");

    connect(btn_prev, SIGNAL(clicked(bool)), this, SLOT(on_click_btn_prev()));
    connect(btn_next, SIGNAL(clicked(bool)), this, SLOT(on_click_btn_next()));
}

bool ImageView::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    setImage(newImage);
    return true;
}

void ImageView::setImage(const QImage &newImage)
{
    image = newImage;
    image_label->setPixmap(QPixmap::fromImage(image));
    scaleFactor = 1.0;
}

void ImageView::on_click_btn_zoom_out()
{
    zoomOut();
}

void ImageView::on_click_btn_zoom_in()
{
    zoomIn();
}

void ImageView::on_click_btn_prev()
{
    emit signal_prev();
}

void ImageView::on_click_btn_next()
{
    emit signal_next();
}

void ImageView::zoomOut()
{
    scaleImage(0.8);
}

void ImageView::zoomIn()
{
    scaleImage(1.2);
}

void ImageView::scaleImage(double factor)
{
    Q_ASSERT(image_label->pixmap());
    scaleFactor *= factor;
    image_label->resize(scaleFactor *image_label->pixmap()->size());
}
