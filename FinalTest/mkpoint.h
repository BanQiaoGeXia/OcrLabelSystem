#ifndef MKPOINT_H
#define MKPOINT_H

#include "shape.h"

class MKPoint : public Shape
{
public:
    MKPoint();

    void paint(QPainter &painter);
};

#endif // MKPOINT_H
