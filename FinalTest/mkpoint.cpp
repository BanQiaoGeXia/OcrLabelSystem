#include "mkpoint.h"

MKPoint::MKPoint()
{

}

void MKPoint::paint(QPainter &painter)
{
    QBrush b = QBrush(QColor(106, 87, 223, 130));
    painter.setBrush(b);
    painter.drawEllipse(end, 20, 20);
    painter.setBrush(Qt::red);
    painter.drawEllipse(end, 2, 2);
}
