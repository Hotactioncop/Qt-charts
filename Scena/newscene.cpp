#include "newscene.h"

NewScene::NewScene(QWidget *parent) : QGraphicsScene(parent)
{
}

void NewScene::resize()
{
    update();
}

void NewScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter,rect);
}


void NewScene::drawItems(QPainter *painter, int numItems, QGraphicsItem *items[], const QStyleOptionGraphicsItem options[], QWidget *widget)
{
    QGraphicsScene::drawItems(painter,numItems,items,options,widget);
}

void NewScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    pos =event->scenePos();
    emit mousePos(pos);
    QGraphicsScene::mouseMoveEvent(event);
}


void NewScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        emit mousePress();
    }
}

void NewScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
    emit mouseRelease();
    }
}
