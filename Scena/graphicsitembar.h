#ifndef GRAPHICSITEMBAR_H
#define GRAPHICSITEMBAR_H

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

class GraphicsItemBar : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit GraphicsItemBar(QObject *parent = nullptr);
//    virtual QRectF boundingRect() const override;
//    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:

public slots:
};

#endif // GRAPHICSITEMBAR_H
