#ifndef GRAPHICSITEMFIBBONACCI_H
#define GRAPHICSITEMFIBBONACCI_H

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
#include <QPointF>
#include <QLinearGradient>

class GraphicsItemFibbonacci : public QObject, public QGraphicsItem
{
    Q_OBJECT
    QPointF startPos;
    QPointF endPos;
public:
    explicit GraphicsItemFibbonacci(QPointF spoint,QPointF epoint,QObject *parent = nullptr);

signals:

public slots:

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // GRAPHICSITEMFIBBONACCI_H
