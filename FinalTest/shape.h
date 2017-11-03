#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include <QPainter>

class Shape
{
public:
    enum Code {
        MKPoint
    };

    Shape();

    void setStart(QPoint s)
    {
        start = s;
    }

    void setEnd(QPoint e)
    {
        end = e;
    }

    QPoint startPoint()
    {
        return start;
    }

    QPoint endPoint()
    {
        return end;
    }

    void virtual paint(QPainter & painter) = 0;

protected:
    QPoint start;
    QPoint end;
};

#endif // SHAPE_H
