#ifndef BEZIERLINE_H
#define BEZIERLINE_H

#include <QObject>
#include <QGraphicsItem>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QFont>
#include <QPoint>
#include <QLinearGradient>


class BezierLine : public QObject, public QGraphicsItem
{
    Q_OBJECT
    QList<QPointF> blist;
    QColor drawColor;
public:
    explicit BezierLine(QList<QPointF>,QColor,QObject *parent = nullptr);
    ~BezierLine();

    QPointF CatmulRom(QPointF p1, QPointF p2, QPointF p3, QPointF p4, double t);
signals:

public slots:

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BEZIERLINE_H
