#ifndef GRAPHICSLINEPOLYGON_H
#define GRAPHICSLINEPOLYGON_H

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

class GraphicsLinePolygon : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int polySize;
    QVector<QPointF> polyVec;
    QLinearGradient fade;
public:
    explicit GraphicsLinePolygon(int,int,int, QObject *parent = nullptr);
    void addPoint(int,int);

signals:

public slots:

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
};

#endif // GRAPHICSLINEPOLYGON_H
