#ifndef NEWSCENE_H
#define NEWSCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QPainter>
#include <QPen>
#include <QPainter>
#include <QBrush>
#include <QPalette>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPoint>

#define BORDER_SIZE         0              //Границы
#define COORDINATE_X1       0              //Координаты (относительная граница)
#define COORDINATE_Y1       0
#define COORDINATE_X2       0
#define COORDINATE_Y2       0

#define AV_CELL_WIDTH       90
#define AV_CELL_HEIGHT      30

#define MINCONTENTWIDTH     640             //На одном экране отображаются данные с шириной не менее 240 точек
#define MINCONTENTHEIGHT    480             //На одном экране отображаются данные по высоте не менее 180 точек
class NewScene : public QGraphicsScene
{
    Q_OBJECT
    int m_x, m_y;
    QPointF pos;
public:
    explicit NewScene(QWidget *parent = nullptr);
    void resize();
signals:
    void mousePos(QPointF&);
    void mousePress();
    void mouseRelease();

    // QGraphicsScene interface
protected:
    virtual void drawBackground(QPainter *painter, const QRectF &rect) override;
    virtual void drawItems(QPainter *painter, int numItems, QGraphicsItem *items[], const QStyleOptionGraphicsItem options[], QWidget *widget) override;

    // QGraphicsScene interface
protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // QGraphicsScene interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // NEWSCENE_H
