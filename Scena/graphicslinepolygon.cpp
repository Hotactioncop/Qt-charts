#include "graphicslinepolygon.h"

GraphicsLinePolygon::GraphicsLinePolygon(int size, int width,int height, QObject *parent) : polySize(size+2),QObject(parent), QGraphicsItem()
{
    fade = QLinearGradient(2+width/2, 2, 2+width/2, height);
    fade.setColorAt(0, QColor(0, 19, 97, 208));
    fade.setColorAt(1, QColor(255, 255, 255,30));
}

void GraphicsLinePolygon::addPoint(int X, int Y)
{
    polyVec.append(QPointF(X,Y));
    if(polySize==polyVec.size()){
        update();
    }
}


void GraphicsLinePolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor("#E1923A"));
    pen.setWidth(1);
    painter->setPen(pen);
    painter->setBrush(fade);
    painter->setOpacity(1.0);   // Прозрачность
    painter->drawConvexPolygon(polyVec);
}


QRectF GraphicsLinePolygon::boundingRect() const
{
    return QRectF();
}
