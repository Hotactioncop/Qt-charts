#ifndef CANDLEBAR_H
#define CANDLEBAR_H

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

class CandleBar : public QObject, public QGraphicsItem
{
    Q_OBJECT
    QFont font;
    int rectX,rectY,rectW,rectZ,lineX,lineY,lineW,lineZ;
//    int rectX=50,rectY=50,rectW=100,rectZ=150,lineX=30,lineY=180;
    bool direction=1;
    int ID; //ID номер бара в основном контейнере
    QBrush brush;
    QLinearGradient gradient;
    int type;
public:
    explicit CandleBar(int,int,int,int,int,int,int,int,int,bool,int, QObject *parent = nullptr);
    bool enter=false;

signals:
    void sendIDinfo(int&);
    void clearIDinfo();

public slots:
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // QGraphicsItem interface
protected:
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif // CANDLEBAR_H
