#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Scena/bezierline.h"
#include <QApplication>
#include <QComboBox>
#include <QDateTime>
#include <QDebug>
#include <QMainWindow>
#include <QSpacerItem>

#include "Scena/candlebar.h"
#include "Scena/graphicslinepolygon.h"
#include "Scena/newscene.h"

#include "Scena/graphicsitemfibbonacci.h"
#include "atrform.h"
#include <QBrush>
#include <QColor>
#include <QDate>
#include <QDateTime>
#include <QDebug>
#include <QDesktopWidget>
#include <QFile>
#include <QFont>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QHash>
#include <QLabel>
#include <QLinearGradient>
#include <QList>
#include <QMouseEvent>
#include <QPair>
#include <QPen>
#include <QPoint>
#include <QSet>
#include <QStringList>
#include <QTime>
#include <set>

using namespace std;
namespace Ui {
class MainWindow;
}
namespace Candle {
struct Bar { //Структура для хранения каждого 15минутного участка
  double open, high, low, close;
  int volume;
  QDateTime time;
  Bar(QDateTime time, double open, double high, double low, double close,
      int vol)
      : time(time), open(open), high(high), low(low), close(close),
        volume(vol) {}
};
struct BuySellPos {
  double open, stopLoss, takeProfit, close, profit;
  bool direction; // 0-down, 1- up;
  int dealDeposit;
  int openBar;
  QString dealLotSize;
  QDateTime timeOpen;
  QDateTime timeClose;
  bool TPpassed;
  BuySellPos(QDateTime timeOpen, double open, double stopLoss,
             double takeProfit, bool direction)
      : timeOpen(timeOpen), open(open), stopLoss(stopLoss),
        takeProfit(takeProfit), direction(direction) {}
};
} // namespace Candle
using namespace Candle;

class MainWindow : public QMainWindow {
  Q_OBJECT
  QString curSets; //Текущие характеристики окна (Имя,тип вывода данных, период)
  QString curName;
  QList<Bar> barList; //храним все дневки в данном контейнере
  QLabel *O, *H, *L, *C, *D;
  enum format { min1, min15, min30, hour, day, week, month };
  format format_type;
  QColor avColor; //цвет скользящей

  bool signalForStart = false;

  bool resizeMark = true; // WheelEvent вызывается дважды. Когда тру - ресайз и
                          // меняем на фолс. Когда фолс - только замена на тру.
  bool graphEnd =
      false; //Вводим булеву для определения, стоит ли график в конце, если да,
             //то при ресайзе, двигается левая сторона, а не правая. Если нет,
             //то бары добавляются и исчезают справа.
  double screenSize;
  double maxSet;
  double minSet;
  int pos = 3;
  int sceneWidth = 600;
  int sceneheight = 480;
  int paddingTop =
      70; //Отступ от края сцены сверху - от него рисуются элементы графика
  int paddingBottom =
      30; //Отступ от края сцены снизу - до него рисуются элементы графика
  int paddingVolume = 0; //Отступ снизу для изображения графика объемов
  int barWidth = 13;
  int barSpace = 3; //Место между барами
  int barPos = 0;
  int bonusSpace = 30;
  int bonusSpaceUp = 90;
  int bonusSpaceDown = 10;
  QBrush brush1;
  QPen pen;       //Ручка для свечного графика
  QPen penLine;   //Ручка для линейного графика
  QPen penCandel; //Ручка для обрамления свечей = 0.
  QPen netPen;    //Ручка для прорисовки сетки
  QPen boxinfo;
  GraphicsLinePolygon *polygon;
  GraphicsItemFibbonacci *fibbonacci;
  QLabel *load;
  AtrForm *atr;
  QList<double> atrList;
  bool showATR;
  bool fibDraw;

  QGraphicsItemGroup *group1;
  QPen crossLine;
  //    bool crossArrow = false;
  QPointF prevMousePoint;
  QPointF mousePoint;

  QPointF startFibbPoint;
  QPointF endFibPoint;

  QGraphicsRectItem *rectDown;
  QGraphicsTextItem *textDown;
  double pixelsize;
  QGraphicsRectItem *rectRight;
  QGraphicsTextItem *textRight;

  QGraphicsRectItem *rectRightPrice;
  QGraphicsTextItem *textRightPrice;

  QGraphicsRectItem *rectDown2;
  QGraphicsRectItem *rectRight2;
  QGraphicsTextItem *textDown2;
  QGraphicsTextItem *textRight2;

  QGraphicsRectItem *crossRect;
  QGraphicsTextItem *crossText;

  QList<QGraphicsTextItem *> axisY;

  QVector<int> barWidthList{27, 13 /*,11*/, 5, 3, 1, 1}; //Размер бара
  QVector<int> barSpaceList{5, 3 /*,5*/, 3, 1, 1, 0}; //Расстояние между барами
  QVector<int> barScrollList{4,  8,  16,
                             32, 64, 128}; //Количество баров для скролла
  int barIndex = 1; //Индекс какой размер бара и расстояние сейчас актуален (13
                    //размер и 2 пикселя расстояние)

  bool ctrlPressed = false;
  double barResize =
      0; /*Поскольку прокрутка колеса мыши вызывает wheelevent дважды, то ввожу
         barResize, который на каждую прокрутку будет увеличиваться на 0.5 и
         операция ресайза будет выполняться один раз за прокрутку колеса мыши.
         При значении 1, barSize обнуляется.*/

  QFont font;
  QFont fontInfo; //Размер информационного текста в левом верхнем углу

  NewScene *scene;
  QVector<QGraphicsTextItem *> listItem;
  QVector<CandleBar *> candleVector; //Контейнер из свечек для вывода на сцену
  QGraphicsTextItem *textInfo;
  QGraphicsTextItem *pair; //Название ценной бумаги в левом верхнем углу
  int type = 0;            // 0-свеча, 1-линия, 2 бар

  QGraphicsLineItem *crossLine1;
  QGraphicsLineItem *crossLine2;
  QGraphicsLineItem *crossLine3;
  QGraphicsLineItem *crossLine4;
  QGraphicsLineItem *lineItem;
  QList<QPointF> bezierList;
  BezierLine *Bezier;
  bool drawLineInCrosses = false;
  bool hideNet = false; //Индикатор- рисовать ли сетку на сцене

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

protected:
  virtual void wheelEvent(QWheelEvent *event) override;
  virtual void resizeEvent(QResizeEvent *event) override;
  virtual void keyPressEvent(QKeyEvent *event) override;
  virtual void keyReleaseEvent(QKeyEvent *event) override;
  void drawSceneItems(int);
  void drawSceneLine(int);
  void drawVolume(int);
  void drawVolume2(int);
  void drawSceneNet();
  void drawGraphic();
  void setTitle();
public slots:
  void showBarInfo(int &);
  void fillStatusBar(QPointF &);
  void getData(QString);
  void addLastPrice(double);
  void movingAverage(int, QColor);
  void drawRedRect();
};

#endif // MAINWINDOW_H
