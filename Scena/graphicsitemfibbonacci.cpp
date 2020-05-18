#include "graphicsitemfibbonacci.h"

GraphicsItemFibbonacci::GraphicsItemFibbonacci(QPointF spoint,QPointF epoint,QObject *parent) : QObject(parent)
{
    startPos=spoint;
    endPos=epoint;
}


QRectF GraphicsItemFibbonacci::boundingRect() const
{
}

void GraphicsItemFibbonacci::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(1);
    painter->setPen(pen);
    painter->drawLine(startPos,QPointF(endPos.x(),startPos.y()));

    painter->drawLine(QPointF(startPos.x(), endPos.y()-(endPos.y()-startPos.y())*0.5),QPointF(endPos.x(),endPos.y()-(endPos.y()-startPos.y())*0.5));
    painter->drawLine(QPointF(startPos.x(), endPos.y()-(endPos.y()-startPos.y())*0.618),QPointF(endPos.x(),endPos.y()-(endPos.y()-startPos.y())*0.618));
    painter->drawLine(QPointF(startPos.x(), endPos.y()-(endPos.y()-startPos.y())*0.382),QPointF(endPos.x(),endPos.y()-(endPos.y()-startPos.y())*0.382));
    painter->drawLine(QPointF(startPos.x(), endPos.y()-(endPos.y()-startPos.y())*0.236),QPointF(endPos.x(),endPos.y()-(endPos.y()-startPos.y())*0.236));
    painter->drawLine(QPointF(startPos.x(),endPos.y()),endPos);
    painter->drawText(QPointF(endPos.x()-18,startPos.y()-3),"100.0");
    painter->drawText(QPointF(endPos.x()-15,endPos.y()-(endPos.y()-startPos.y())*0.5-3),"50.0");
    painter->drawText(QPointF(endPos.x()-15,endPos.y()-(endPos.y()-startPos.y())*0.618-3),"61.8");
    painter->drawText(QPointF(endPos.x()-15,endPos.y()-(endPos.y()-startPos.y())*0.382-3),"38.2");
    painter->drawText(QPointF(endPos.x()-15,endPos.y()-(endPos.y()-startPos.y())*0.236-3),"23.6");
    painter->drawText(QPointF(endPos.x()-10,endPos.y()-3),"0.0");
}
