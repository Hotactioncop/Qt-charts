#include "bezierline.h"

BezierLine::BezierLine(QList<QPointF> list, QColor col, QObject *parent) : blist(list),QObject(parent)
{
    drawColor=col;
}

BezierLine::~BezierLine()
{
}

QPointF BezierLine::CatmulRom(QPointF p1, QPointF p2, QPointF p3, QPointF p4, double t)
{
    return 0.5*(-t*(1-t)*(1-t)*p1+(2-5*t*t+3*t*t*t)*p2+t*(1+4*t-3*t*t)*p3-t*t*(1-t)*p4);
}


QRectF BezierLine::boundingRect() const
{
}

void BezierLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setPen(drawColor);
        double tStart=0, tFinish=0;
        int stepCount = 10;
        for(int j=0; j<stepCount; ++j)
        {
            tStart = tFinish;
            tFinish += 1.0/stepCount;

            int i=0;
            painter->drawLine(CatmulRom(blist.at(i),blist.at(i),blist.at(i+1),blist.at(i+2),tStart), CatmulRom(blist.at(i),blist.at(i),blist.at(i+1),blist.at(i+2),tFinish));  //дублирование первой точки для построения первого сегмента p1-p2
            for (int l=0; l<blist.size()-5; l++){
                painter->drawLine(CatmulRom(blist.at(i),blist.at(i+1),blist.at(i+2),blist.at(i+3),tStart), CatmulRom(blist.at(i),blist.at(i+1),blist.at(i+2),blist.at(i+3),tFinish));  //p2-p3
                i++;
            }
            painter->drawLine(CatmulRom(blist.at(i),blist.at(i+1),blist.at(i+2),blist.at(i+3),tStart), CatmulRom(blist.at(i),blist.at(i+1),blist.at(i+2),blist.at(i+3),tFinish));  //p2-p3
            painter->drawLine(CatmulRom(blist.at(i+1),blist.at(i+2),blist.at(i+3),blist.at(i+4),tStart), CatmulRom(blist.at(i+1),blist.at(i+2),blist.at(i+3),blist.at(i+4),tFinish));  //дублирование первой точки для построения первого сегмента p1-p2
            painter->drawLine(CatmulRom(blist.at(i+2),blist.at(i+3),blist.at(i+4),blist.at(i+4),tStart), CatmulRom(blist.at(i+2),blist.at(i+3),blist.at(i+4),blist.at(i+4),tFinish));  //дублирование первой точки для построения первого сегмента p1-p2
        }
}
