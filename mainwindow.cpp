#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    O=nullptr;
    H=nullptr;
    L=nullptr;
    C=nullptr;
    D=nullptr;
    atr=nullptr;
    showATR=false;
    fibDraw=false;


//    QPalette darkPalette;

//    // Настраиваем палитру для цветовых ролей элементов интерфейса
//    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
//    darkPalette.setColor(QPalette::WindowText, Qt::white);
//    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
//    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
//    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
//    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
//    darkPalette.setColor(QPalette::Text, Qt::white);
//    darkPalette.setColor(QPalette::BrightText, Qt::red);
//    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
//    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
//    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

////     Устанавливаем данную палитру
//    this->setPalette(darkPalette);
    ui->widget->setMinimumSize(800,600);

    pair=nullptr;
    crossLine1=nullptr;
    crossLine2=nullptr;
    rectDown=nullptr;
    rectRight=nullptr;
    textDown=nullptr;
    textRight=nullptr;
    signalForStart=false;
    crossLine3=nullptr;
    crossLine4=nullptr;
    textDown2=nullptr;
    textRight2=nullptr;
    lineItem=nullptr;
    crossRect=nullptr;
    crossText=nullptr;
    format_type=day;
    fibbonacci=nullptr;
    atr=nullptr;
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    QBrush brush(QColor("#313233"));    //QColor("#313233")
    scene = new NewScene(this);
    scene->setBackgroundBrush(brush);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->adjustSize();
//    load=new QLabel(ui->graphicsView);
//    load->setAlignment(Qt::AlignCenter);
//    load->setStyleSheet("color: rgb(50, 0, 70)");
//    load->setText("LOADING");
//    QApplication::setOverrideCursor(Qt::WaitCursor);
    connect(ui->LoadButton,&QPushButton::clicked,[=]{
        if(ui->comboName->currentIndex()==0)return;
        if(ui->comboBox->currentIndex()==0)return;
        if(ui->comboBox->currentIndex()==1){
            format_type=min1;
        }
        if(ui->comboBox->currentIndex()==2){
            format_type=min15;
        }
        if(ui->comboBox->currentIndex()==3){
            format_type=min30;
        }
        if(ui->comboBox->currentIndex()==4){
            format_type=hour;
        }
        if(ui->comboBox->currentIndex()==5){
            format_type=day;
        }
        if(pair!=nullptr){
            delete pair;
            pair = nullptr;
        }
        for(auto it:candleVector){
                delete it;
            }
        candleVector.clear();
        barList.clear();
        scene->clear();
        signalForStart=false;
        curName=ui->comboName->currentText();
        QString newSet = curName+"_"+ui->comboBox->currentText()+"_"+ui->dateFrom->date().toString("dd.MM.yyyy")+"_"+ui->dateTo->date().toString("dd.MM.yyyy");
        getData(curName);
        this->setWindowTitle(curName+" "+ui->comboBox->currentText()+" "+ui->dateFrom->date().toString("dd.MM.yyyy")+"-"+ui->dateTo->date().toString("dd.MM.yyyy"));

        curSets=newSet;
    });
    connect(ui->pushButtonCandle,&QPushButton::clicked,[this]{
        if(!signalForStart){return;}
        if(type==0){
            ui->pushButtonCandle->setChecked(true);
            return;
        }else{
            type=0;
            ui->pushButtonLine->setChecked(false);
            ui->pushButtonBar->setChecked(false);
            sceneWidth=ui->widget->width()-70;
            sceneheight=ui->widget->height()-2;
            scene->setSceneRect(0,0,sceneWidth,sceneheight);

            if(barPos+(sceneWidth)/(barWidth+barSpace)>barList.size()){
                graphEnd=true;
                barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
            }
            if(graphEnd){
                barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
            }
            drawSceneItems(3+barWidth/2+barSpace);
        }
    });
    connect(ui->pushButtonLine,&QPushButton::clicked,[this]{
        if(!signalForStart){return;}
        if(type==1){
            ui->pushButtonLine->setChecked(true);
            return;
        }else{
            type=1;
            ui->pushButtonCandle->setChecked(false);
            ui->pushButtonBar->setChecked(false);
            sceneWidth=ui->widget->width()-70;
            sceneheight=ui->widget->height()-2;
            scene->setSceneRect(0,0,sceneWidth,sceneheight);

            if(barPos+(sceneWidth)/(barWidth+barSpace)>barList.size()){
                graphEnd=true;
                barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
            }
            if(graphEnd){
                barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
            }
            if(barPos<1){barPos=0;}
            drawSceneLine(3+barWidth/2+barSpace);
        }
    });
    connect(ui->pushButtonBar,&QPushButton::clicked,[this]{
        if(!signalForStart){return;}
        if(type==2){
            ui->pushButtonBar->setChecked(true);
            return;
        }else{
            type=2;
            ui->pushButtonLine->setChecked(false);
            ui->pushButtonCandle->setChecked(false);
            sceneWidth=ui->widget->width()-70;
            sceneheight=ui->widget->height()-2;
            scene->setSceneRect(0,0,sceneWidth,sceneheight);

            if(barPos+(sceneWidth)/(barWidth+barSpace)>barList.size()){
                graphEnd=true;
                barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
            }
            if(graphEnd){
                barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
            }
            drawSceneItems(3+barWidth/2+barSpace);
        }
    });
    connect(ui->pushButtonVolume,&QPushButton::toggled,[this]{
        if(ui->pushButtonVolume->isChecked()){
            paddingVolume=128;
        }else{
            paddingVolume=0;
        }
        if(type==1){
            drawSceneLine(3+barWidth/2+barSpace);
        }else{
            drawSceneItems(3+barWidth/2+barSpace);
        }
    });
    connect(ui->pushButtonVolume_2,&QPushButton::toggled,[this]{
        if(type==1){
            drawSceneLine(3+barWidth/2+barSpace);
        }else{
            drawSceneItems(3+barWidth/2+barSpace);
        }
    });

    if(D==nullptr){
        D=new QLabel(this);
        D->setFixedWidth(70);
        ui->statusbar->addPermanentWidget(D);
        O=new QLabel(this);
        O->setFixedWidth(50);
        ui->statusbar->addPermanentWidget(O);
        H=new QLabel(this);
        H->setFixedWidth(50);
        ui->statusbar->addPermanentWidget(H);
        L=new QLabel(this);
        L->setFixedWidth(50);
        ui->statusbar->addPermanentWidget(L);
        C=new QLabel(this);
        C->setFixedWidth(50);
        ui->statusbar->addPermanentWidget(C);
    }
    connect(scene,SIGNAL(mousePos(QPointF&)),this,SLOT(fillStatusBar(QPointF&)));
    connect(scene,&NewScene::mousePress,[=]{
        prevMousePoint=mousePoint;
        drawLineInCrosses=true;
        if(ui->pushButtonFibbonacci->isChecked()){
            fibDraw=true;
        }
    });
    connect(scene,&NewScene::mouseRelease,[=]{
        drawLineInCrosses=false;
        if(ui->pushButtonFibbonacci->isChecked()){
            fibDraw=false;
            if(fibbonacci!=nullptr){
                delete fibbonacci;
                fibbonacci=nullptr;
            }
            ui->pushButtonFibbonacci->setChecked(false);
        }
    });
    connect(ui->pushButtonArrow,&QPushButton::clicked,[=]{
                ui->pushButtonCursor->setChecked(false);
                ui->pushButtonArrow->setChecked(true);
            setCursor(Qt::ArrowCursor);
                if(signalForStart){
                    if(type==1){
                        drawSceneLine(3+barWidth/2+barSpace);
                    }else{
                        drawSceneItems(3+barWidth/2+barSpace);
                    }
                }
    });
    connect(ui->pushButtonCursor,&QPushButton::clicked,[=]{
                ui->pushButtonArrow->setChecked(false);
                ui->pushButtonCursor->setChecked(true);
            setCursor(Qt::CrossCursor);
                if(signalForStart){
                    if(type==1){
                        drawSceneLine(3+barWidth/2+barSpace);
                    }else{
                        drawSceneItems(3+barWidth/2+barSpace);
                    }
                }
    });
    connect(ui->checkBoxNet,&QCheckBox::toggled,[=]{
        if(ui->checkBoxNet->isChecked()){
            hideNet=true;
            if(!signalForStart){return;}
            if(type==1){
                drawSceneLine(3+barWidth/2+barSpace);
            }else{
                drawSceneItems(3+barWidth/2+barSpace);
            }
        }else{
            hideNet=false;
            if(!signalForStart){return;}
            if(type==1){
                drawSceneLine(3+barWidth/2+barSpace);
            }else{
                drawSceneItems(3+barWidth/2+barSpace);
            }
        }
    });
    connect(ui->pushButtonATR,&QPushButton::clicked,[=]{
        if(atr!=nullptr){
            delete atr;
        }
        atr=new AtrForm();
        atr->show();
        connect(atr,SIGNAL(createAverageLine(int,QColor)),this,SLOT(movingAverage(int,QColor)));
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(!signalForStart){
        return;
    }
    if(!resizeMark){                                //Поскольку wheelevent вызывается дважды - используем бул, чтобы отсекать один лишний вызов.
        resizeMark=true;
        return;
    }
    if(drawLineInCrosses){return;}
    resizeMark=false;
    if (event->delta() > 0) {                       //Если промотка вправо
        if(ctrlPressed){                            //Зум увеличиваем, если зажат ctrl
            if(barIndex+1<barWidthList.size()){     //Если инкрементированный индекс меньше размера контейнера, в котором хранятся величины свечей
                barIndex++;
                barWidth=barWidthList[barIndex];
                barSpace=barSpaceList[barIndex];
                if(barPos+(sceneWidth)/(barWidth+barSpace)>barList.size()){ //Если при этом первый бар на рисунке+все остальные бары больше размера контейнера, в котором хранятся все бары:
                    if(barList.size()-(sceneWidth)/(barWidth+barSpace)<0){
                        barIndex--;
                        barWidth=barWidthList[barIndex];
                        barSpace=barSpaceList[barIndex];
                        return;}
                    graphEnd=true;                                          //Устанавливаем метку для ресайза, что достигли конца
                    barPos=barList.size()-(sceneWidth)/(barWidth+barSpace); //Устанавливаем так, чтобы на экране выводились все бары включая последний в контейнере.
                }else{
                    graphEnd=false;                                          //Устанавливаем метку для ресайза, что покинули конец
                }
            }else{
                return;
            }
        }else{
            if(barPos+barScrollList[barIndex]+(sceneWidth)/(barWidth+barSpace)>barList.size()){ //Если при прокрутке вперед, последний бар выходит за границу контейнера
                graphEnd=true;                                                                  //Устанавливаем метку для ресайза, что достигли конца
                barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);                         //Устанавливаем так, чтобы на экране выводились все бары включая последний в контейнере.
            }else{
                barPos+=barScrollList[barIndex];           //Промотка по бару
            }
        }
        if(type==1){                                                                               //Выводим на экран тот график, чей индекс стоит
            drawSceneLine(3+barWidth/2+barSpace);
        }else{
            drawSceneItems(3+barWidth/2+barSpace);
        }
        if(ui->pushButtonCursor->isChecked()){      //Вывести курсор крест, если активировано меню
        }
    }else{                                 //Если промотка влево
        if(ctrlPressed){                           //Зум уменьшаем, если зажат ctrl
            if(barIndex-1>=0){
                barIndex--;
                barWidth=barWidthList[barIndex];
                barSpace=barSpaceList[barIndex];
                if(barPos+(sceneWidth)/(barWidth+barSpace)>barList.size()){
                    if(barList.size()-(sceneWidth)/(barWidth+barSpace)<0){
                        barIndex++;
                        barWidth=barWidthList[barIndex];
                        barSpace=barSpaceList[barIndex];
                        return;}
                    graphEnd=true;
                    barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
                }else if(barPos<1){    //barPos-(sceneWidth)/(barWidth+barSpace)<1
                    barPos=0;
                }else{
                    graphEnd=false;
                }
            }else{
                return;
            }
        }else{
            if(barPos-barScrollList[barIndex]<1){
                barPos=0;                                               //Если вышел за левую границу
            }else{
                graphEnd=false;
                barPos-=barScrollList[barIndex];           //Промотка по бару
            }
        }
        if(type==1){
            drawSceneLine(3+barWidth/2+barSpace);
        }else{
            drawSceneItems(3+barWidth/2+barSpace);
        }
        if(ui->pushButtonCursor->isChecked()){      //Вывести курсор крест, если активировано меню
        }
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if(signalForStart){
        sceneWidth=ui->widget->width()-70;
        sceneheight=ui->widget->height()-2;
        scene->setSceneRect(0,0,sceneWidth,sceneheight);

        if(barPos+(sceneWidth)/(barWidth+barSpace)>barList.size()){
            graphEnd=true;
            barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
        }
        if(graphEnd){
            barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
        }
        if(type==1){
            drawSceneLine(3+barWidth/2+barSpace);
        }else{
            drawSceneItems(3+barWidth/2+barSpace);
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!signalForStart)return;
    if(event->modifiers()==Qt::ControlModifier){
        ctrlPressed=true;
    }else if(event->key()==Qt::Key_Right || event->key()==Qt::Key_F12){
        if(barPos+1+(sceneWidth)/(barWidth+barSpace)>barList.size()){
            graphEnd=true;
            barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
        }else{
            barPos++;
        }
        if(!type){
            drawSceneItems(3+barWidth/2+barSpace);
        }else{
            drawSceneLine(3+barWidth/2+barSpace);
        }
    }else if(event->key()==Qt::Key_Left || event->key()==Qt::Key_F11){

        if(graphEnd){
            graphEnd=false;
        }
        if(barPos-1<0){
            return;
        }
        barPos--;
        if(!type){
            drawSceneItems(3+barWidth/2+barSpace);
        }else{
            if(barPos<1){
                return;
            }
            drawSceneLine(3+barWidth/2+barSpace);
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(!signalForStart)return;

    ctrlPressed=false;
}

void MainWindow::drawSceneItems(int put)
{
    if(pair!=nullptr){
        delete pair;
        pair=nullptr;
    }
    for(auto it:candleVector){
        delete it;
    }
    candleVector.clear();
    if(crossLine1!=nullptr){
        scene->removeItem(crossLine1);
        scene->removeItem(crossLine2);
        delete crossLine1;
        delete crossLine2;
        crossLine1=nullptr;
        crossLine2=nullptr;
        scene->update();
    }
    if(rectDown!=nullptr){
        scene->removeItem(rectDown);
        scene->removeItem(rectRight);
        scene->removeItem(textDown);
        scene->removeItem(textRight);
        delete rectDown;
        delete rectRight;
        delete textDown;
        delete textRight;
        rectDown=nullptr;
        rectRight=nullptr;
        textDown=nullptr;
        textRight=nullptr;
        scene->update();
    }
    scene->clear();
    //Очищаем форму от предыдущих элементов
    if(!hideNet){
        drawSceneNet();
    }
    if(ui->pushButtonVolume->isChecked()){
        scene->addLine(2,sceneheight-paddingBottom-paddingVolume+2,sceneWidth,sceneheight-paddingBottom-paddingVolume+2,pen);             //Наносим черту разделяющую основной график от графика объема
    }

    std::multiset<double> iSet;
    for (int i=barPos; i<(barPos+(sceneWidth)/(barWidth+barSpace)); i++){      // Добавляем в упорядоченный контейнер все показатели (хай, лоу, опен, клоуз) для опеределения максимума и минимума для подгона окна
        iSet.insert(barList.at(i).high);
        iSet.insert(barList.at(i).low);
    }
    maxSet = *iSet.rbegin();
    minSet = *iSet.begin();

    double screenSize = (sceneheight-paddingTop-paddingBottom-paddingVolume)/(maxSet-minSet);      //-100, чтобы оставить 30 пикселей снизу и 70 сверху от бара

    pair = scene->addText(curName,fontInfo);
    pair->setDefaultTextColor(Qt::white);
    pair->moveBy(0,0);
    bezierList.clear();
    if(ui->pushButtonVolume_2->isChecked()){
        drawVolume2(3);
    }
//    qDebug() << "BARPOS=" << barPos;
    for(int i=barPos; i<(barPos+(sceneWidth)/(barWidth+barSpace)); i++){   //Пробегаем от индекса бара, содержащегося в контейнере barList
        double size = abs(barList[i].close-barList[i].open);    //Разница между открытием и закрытием для изображения бара на экране
        if(barList[i].close>=barList[i].open){                   //Если в рост
            if(i && barList[i-1].time.date().month()!=barList[i].time.date().month()){                               //Если начало дня, то добавляем вертикальный разделитель(линию)
                scene->addLine(put+barWidth/2,2,put+barWidth/2,sceneheight-paddingBottom-paddingVolume,penLine);
            }
            CandleBar *bbbar = new CandleBar(i,put,bonusSpace+(maxSet-barList[i].close)*screenSize,barWidth,size*screenSize,put+barWidth/2,bonusSpace+(maxSet-barList[i].high)*screenSize,put+barWidth/2,bonusSpace+(maxSet-barList[i].low)*screenSize,1,type,scene);
            scene->addItem(bbbar);
            candleVector.push_back(bbbar);
            connect(bbbar,SIGNAL(sendIDinfo(int&)),this,SLOT(showBarInfo(int&)));
            connect(bbbar,&CandleBar::clearIDinfo,[this]{
               scene->removeItem(textInfo);
            });
            bbbar=nullptr;
            if(showATR){
                bezierList.push_back(QPointF(put+barWidth/2,int(bonusSpace+(maxSet-atrList[i])*screenSize)));
            }

        }else{
            if(i && barList[i-1].time.date().month()!=barList[i].time.date().month()){                               //Если начало дня, то добавляем вертикальный разделитель(линию)
                scene->addLine(put+barWidth/2,2,put+barWidth/2,sceneheight-paddingBottom-paddingVolume,penLine);
            }
            CandleBar *bbbar = new CandleBar(i,put,bonusSpace+(maxSet-barList[i].open)*screenSize,barWidth,size*screenSize,put+barWidth/2,bonusSpace+(maxSet-barList[i].high)*screenSize,put+barWidth/2,bonusSpace+(maxSet-barList[i].low)*screenSize,0,type,scene);
            scene->addItem(bbbar);
            candleVector.push_back(bbbar);
            connect(bbbar,SIGNAL(sendIDinfo(int&)),this,SLOT(showBarInfo(int&)));
            connect(bbbar,&CandleBar::clearIDinfo,[this]{
               scene->removeItem(textInfo);
            });
            bbbar=nullptr;
            if(showATR){
                bezierList.push_back(QPointF(put+barWidth/2,int(bonusSpace+(maxSet-atrList[i])*screenSize)));
            }

        }

        put+=(barWidth+barSpace);
    }
    scene->addRect(2+sceneWidth,2,ui->widget->width()-2-sceneWidth,sceneheight-paddingBottom,QPen(QColor("#313233")), QBrush(QColor("#313233")));             //Закрашиваем правую сторону-если фигура выходит за рамку
    scene->addRect(2,2,sceneWidth,sceneheight-paddingBottom,pen);             //Каждый раз рисуем рамку экрана

    if(showATR){
        if(bezierList.size()>(sceneWidth)/(barWidth+barSpace)){
            while(bezierList.size()>(sceneWidth)/(barWidth+barSpace)){
                bezierList.pop_back();
            }
        }
    }

    put=3;
    drawVolume(put);

    pixelsize=(maxSet-minSet)/double(sceneheight-paddingTop-paddingBottom-paddingVolume+2);
    double begin = minSet-pixelsize*(paddingTop-paddingBottom+3)+pixelsize*32;      //Начинаю заполнять не с самого низа
    for(int i=sceneheight-28-paddingVolume-32; i>10; i-=32){

        scene->addLine(sceneWidth+2,i,sceneWidth+5,i,pen);
        QGraphicsTextItem *textitem = scene->addText(QString::number(begin,'f',5),font);
        textitem->setDefaultTextColor(Qt::white);
        textitem->moveBy(sceneWidth+6,i-8);
        begin+=pixelsize*32;
        textitem=nullptr;
    }

    bool whenToPutDate = true;
    for(int i=2; i<sceneWidth; i+=32){
        if(whenToPutDate){
            scene->addLine(i,sceneheight-27,i,sceneheight-23,pen);
            int whichBar=i/(barWidthList[barIndex]+barSpaceList[barIndex])-1;
            if(barPos+whichBar<0){
                if (format_type==day){
                    QGraphicsTextItem *textitem = scene->addText(barList[0].time.addDays(-1).toString("yyyy MMM dd"),font);
                    textitem->setDefaultTextColor(Qt::white);
                    textitem->moveBy(i,sceneheight-27);
                }else /*if(format_type==hour || min1 || min15 || min30 || H)*/{
                    QGraphicsTextItem *textitem = scene->addText(barList[0].time.addDays(-1).toString("dd MMM hh:mm"),font);
                    textitem->setDefaultTextColor(Qt::white);
                    textitem->moveBy(i,sceneheight-27);
                }
                whenToPutDate=false;
            }else{
                if (format_type==day){
                    QGraphicsTextItem *textitem = scene->addText(barList[barPos+whichBar].time.toString("yyyy MMM dd"),font);
                    textitem->setDefaultTextColor(Qt::white);
                    textitem->moveBy(i,sceneheight-27);
                }else /*if(format_type==hour || min1 || min15 || min30 || H)*/{
                    QGraphicsTextItem *textitem = scene->addText(barList[barPos+whichBar].time.toString("dd MMM hh:mm"),font);
                    textitem->setDefaultTextColor(Qt::white);
                    textitem->moveBy(i,sceneheight-27);
                }

                whenToPutDate=false;
            }
        }else{
            scene->addLine(i,sceneheight-27,i,sceneheight-25,pen);
            whenToPutDate=true;
        }
    }

    drawRedRect();  //Рисуем красный квадрат
    if(showATR){
        BezierLine *bline = new BezierLine(bezierList,avColor);
        scene->addItem(bline);
        bline=nullptr;
    }
    ui->graphicsView->update();
}

void MainWindow::drawSceneLine(int put)
{
    if(pair!=nullptr){
        delete pair;
        pair=nullptr;
    }
    for(auto it:candleVector){
        delete it;
    }
    candleVector.clear();
    if(crossLine1!=nullptr){
        scene->removeItem(crossLine1);
        scene->removeItem(crossLine2);
        delete crossLine1;
        delete crossLine2;
        crossLine1=nullptr;
        crossLine2=nullptr;
        scene->update();
    }
    if(rectDown!=nullptr){
        scene->removeItem(rectDown);
        scene->removeItem(rectRight);
        scene->removeItem(textDown);
        scene->removeItem(textRight);
        delete rectDown;
        delete rectRight;
        delete textDown;
        delete textRight;
        rectDown=nullptr;
        rectRight=nullptr;
        textDown=nullptr;
        textRight=nullptr;
        scene->update();
    }
    scene->clear();                                 //Очищаем форму от предыдущих элементов
    if(!hideNet){
        drawSceneNet();
    }
    std::multiset<double> iSet;
    for (int i=barPos; i<(barPos+(sceneWidth)/(barWidth+barSpace)); i++){      // Добавляем в упорядоченный контейнер все показатели (хай, лоу, опен, клоуз) для опеределения максимума и минимума для подгона окна
        iSet.insert(barList.at(i).high);
        iSet.insert(barList.at(i).low);
    }
    maxSet = *iSet.rbegin();
    minSet = *iSet.begin();
    double screenSize = (sceneheight-paddingTop-paddingBottom-paddingVolume)/(*iSet.rbegin()-*iSet.begin());      //-70, чтобы оставить 30 пикселей снизу и сверху от бара
    int i=barPos;
    if(ui->pushButtonVolume_2->isChecked()){
        drawVolume2(3);
    }
    put-=(barWidth/2+barSpace+1);
    polygon = new GraphicsLinePolygon((barPos+(sceneWidth)/(barWidth+barSpace))-i,sceneWidth,sceneheight,scene);
    polygon->addPoint(put,sceneheight-paddingBottom-paddingVolume);
    polygon->addPoint(put,bonusSpace+(maxSet-barList[i].close)*screenSize);
    pair = scene->addText(curName,fontInfo);
    pair->setDefaultTextColor(Qt::white);
    pair->moveBy(0,0);
    for(; i<(barPos+(sceneWidth)/(barWidth+barSpace)); i++){   //Пробегаем от индекса бара, содержащегося в контейнере barList
        qDebug() << i;
        if(i && barList[i-1].time.date().month()!=barList[i].time.date().month()){                               //Если начало дня, то добавляем вертикальный разделитель(линию)
            scene->addLine(put+barWidth+barSpace,2,put+barWidth+barSpace,sceneheight-paddingBottom-paddingVolume,penLine);
        }
        polygon->addPoint(put+(barWidth+barSpace),bonusSpace+(maxSet-barList[i].close)*screenSize);
        put+=(barWidth+barSpace);
    }
    qDebug() << "End";
    polygon->addPoint(put,sceneheight-paddingBottom-paddingVolume);
    scene->addItem(polygon);
    polygon=nullptr;
    scene->addRect(2+sceneWidth,2,ui->widget->width()-2-sceneWidth,sceneheight-paddingBottom,QPen(QColor("#313233")), QBrush(QColor("#313233")));             //закрашиваем правую сторону-если фигура выходит за рамку
    scene->addRect(2,2,sceneWidth,sceneheight-paddingBottom,pen);             //Каждый раз рисуем рамку экрана
    if(ui->pushButtonVolume->isChecked()){
        scene->addLine(2,sceneheight-paddingBottom-paddingVolume+2,sceneWidth,sceneheight-paddingBottom-paddingVolume+2,pen);             //Каждый раз рисуем рамку экрана
    }
    put=3;
    drawVolume(3);
    pixelsize=(maxSet-minSet)/double(sceneheight-paddingTop-paddingBottom-paddingVolume+2);
    double begin = minSet-pixelsize*(paddingTop-paddingBottom+3)+pixelsize*32;
       for(int i=sceneheight-28-paddingVolume-32; i>10; i-=32){
           scene->addLine(sceneWidth+2,i,sceneWidth+5,i,pen);
                   QGraphicsTextItem *textitem = scene->addText(QString::number(begin,'f',5),font);
                   textitem->setDefaultTextColor(Qt::white);
                   textitem->moveBy(sceneWidth+6,i-8);
                   begin+=pixelsize*32;

       }
    bool whenToPutDate = true;
    for(int i=2; i<sceneWidth; i+=32){
        if(whenToPutDate){
            scene->addLine(i,sceneheight-27,i,sceneheight-23,pen);
            int whichBar=i/(barWidthList[barIndex]+barSpaceList[barIndex])-1;
            QGraphicsTextItem *textitem;
            qDebug() << barPos+whichBar;
            if(barPos+whichBar<0){
                if (format_type==day){
                    QGraphicsTextItem *textitem = scene->addText(barList[0].time.addDays(-1).toString("yyyy MMM dd"),font);
                    textitem->setDefaultTextColor(Qt::white);
                    textitem->moveBy(i,sceneheight-27);
                }else /*if(format_type==hour || min1 || min15 || min30 || H)*/{
                    QGraphicsTextItem *textitem = scene->addText(barList[0].time.addDays(-1).toString("dd MMM hh:mm"),font);
                    textitem->setDefaultTextColor(Qt::white);
                    textitem->moveBy(i,sceneheight-27);
                }
                whenToPutDate=false;
            }else{
                if (format_type==day){
                    QGraphicsTextItem *textitem = scene->addText(barList[barPos+whichBar].time.toString("yyyy MMM dd"),font);
                    textitem->setDefaultTextColor(Qt::white);
                    textitem->moveBy(i,sceneheight-27);
                }else /*if(format_type==hour || min1 || min15 || min30 || H)*/{
                    QGraphicsTextItem *textitem = scene->addText(barList[barPos+whichBar].time.toString("dd MMM hh:mm"),font);
                    textitem->setDefaultTextColor(Qt::white);
                    textitem->moveBy(i,sceneheight-27);
                }

                whenToPutDate=false;
            }
        }else{
            scene->addLine(i,sceneheight-27,i,sceneheight-25,pen);
            whenToPutDate=true;
        }
    }
    drawRedRect();  //Рисуем красный квадрат
    ui->graphicsView->update();
}

void MainWindow::drawVolume(int)
{
    //Рисуем шкалу объема в нижней части экрана
    if(!ui->pushButtonVolume->isChecked())return;
    QLinearGradient gradient=QLinearGradient(2,sceneheight-paddingVolume-paddingBottom, 2,sceneheight);
    gradient.setColorAt(1, QColor(255, 255, 255,30));
    gradient.setColorAt(0, QColor(2, 176, 177, 208));
    QBrush brush = QBrush(gradient);
    QPen pen;
    pen.setBrush(brush);
    std::multiset<double> iSet;
    double maxVolume;
    double minVolume;
    for (int i=barPos; i<(barPos+(sceneWidth)/(barWidth+barSpace)); i++){      // Добавляем в упорядоченный контейнер все показатели (хай, лоу, опен, клоуз) для опеределения максимума и минимума для подгона окна
        iSet.insert(barList.at(i).volume);
    }
    maxVolume = *iSet.rbegin();
    minVolume = *iSet.begin();
    double pixelsize = (paddingVolume-20)/(maxVolume-minVolume);
    int put=3+barSpace+barWidth/2;
    for(int i=barPos; i<(barPos+(sceneWidth)/(barWidth+barSpace)); i++){   //Пробегаем от индекса бара, содержащегося в контейнере barList
        scene->addRect(QRectF(QPointF(put,sceneheight-paddingBottom-paddingVolume+10+(maxVolume-barList[i].volume)*pixelsize),QPointF(put+barWidth,sceneheight-paddingBottom)),pen,brush);
        put+=(barWidth+barSpace);
    }

    pixelsize=(maxVolume-minVolume)/double(paddingBottom-20);
    int begin = minVolume+10*pixelsize;
       for(int i=sceneheight-28; i>sceneheight-paddingBottom-paddingVolume; i-=32){
           scene->addLine(sceneWidth+2,i,sceneWidth+5,i,pen);
                   QGraphicsTextItem *textitem = scene->addText(QString::number(begin/500*500),font);
                   textitem->setDefaultTextColor(Qt::white);
                   textitem->moveBy(sceneWidth+6,i-8);
                   begin+=pixelsize*32;
                   textitem=nullptr;

       }

       scene->update();
}

void MainWindow::drawVolume2(int)
{
    //Рисуем шкалу объема в нижней части экрана
    QLinearGradient gradient=QLinearGradient(2,2, 2,sceneheight);
    gradient.setColorAt(1, QColor(255, 255, 255,30));
    gradient.setColorAt(0, QColor(2, 176, 177, 100));
    QBrush brush = QBrush(gradient);
    QPen pen;
    pen.setBrush(brush);
//    pen.setColor(Qt::white);
    std::multiset<double> iSet;
    double maxVolume;
    double minVolume;
    for (int i=barPos; i<(barPos+(sceneWidth)/(barWidth+barSpace)); i++){      // Добавляем в упорядоченный контейнер все показатели (хай, лоу, опен, клоуз) для опеределения максимума и минимума для подгона окна
        iSet.insert(barList.at(i).volume);
    }
    maxVolume = *iSet.rbegin();
    minVolume = *iSet.begin();
    double pixelsize = (sceneheight-paddingTop)/(maxVolume-minVolume);
    int put=3+barSpace+barWidth/2;
    for(int i=barPos; i<(barPos+(sceneWidth)/(barWidth+barSpace)); i++){   //Пробегаем от индекса бара, содержащегося в контейнере barList
        scene->addRect(QRectF(QPointF(put,paddingBottom+(maxVolume-barList[i].volume)*pixelsize),QPointF(put+barWidth,sceneheight-paddingBottom)),pen,brush);
        put+=(barWidth+barSpace);
    }
    scene->update();
}

void MainWindow::drawSceneNet()
{
    if(hideNet)return;
    for(int i=34; i<sceneWidth; i+=32){
        scene->addLine(i,3,i,sceneheight-30,netPen);
    }

    for(int i=sceneheight-60; i>2; i-=32){
        scene->addLine(3,i,sceneWidth-2,i,netPen);
    }
}

void MainWindow::showBarInfo(int &ID)
{
    if (format_type==day){
        textInfo = scene->addText(QString("High: %1\tOpen: %3\tDate: %5\nLow: %2\tClose: %4").arg(barList[ID].high).arg(barList[ID].low)
                                  .arg(barList[ID].open).arg(barList[ID].close).arg(barList[ID].time.toString("yyyy MMM dd dddd")),fontInfo);
    }else{
        textInfo = scene->addText(QString("High: %1\tOpen: %3\tDate: %5\nLow: %2\tClose: %4").arg(barList[ID].high).arg(barList[ID].low)
                                  .arg(barList[ID].open).arg(barList[ID].close).arg(barList[ID].time.toString("yyyy MMM dd hh:mm")),fontInfo);
    }
    textInfo->setDefaultTextColor(Qt::white);
    textInfo->moveBy(100,0);
}

void MainWindow::fillStatusBar(QPointF& point)
{
    if (!barList.size())return;
        if(point.rx()>2 && point.rx()<sceneWidth && point.ry()>2 && point.ry()<sceneheight-30){
            qDebug() << 0;
            int bar = barPos+(point.rx()-(3+barWidth/2+barSpace))/(barWidth+barSpace);
            bar=(bar>=barList.size())?barList.size()-1:bar;
            qDebug() << 1;
            qDebug() << "barlist.size()=" << barList.size();
            qDebug() << "bar=" << bar;
            qDebug() << barList[bar].time.toString("dd MMM hh:mm");
            if (format_type==day){
                D->setText(barList[bar].time.toString("yyyy.MM.dd"));
            }else{
                D->setText(barList[bar].time.toString("dd MMM hh:mm"));
            }
            qDebug() << 2;
            O->setText(QString("O: %1").arg(barList[bar].open));
            H->setText(QString("H: %1").arg(barList[bar].high));
            L->setText(QString("L: %1").arg(barList[bar].low));
            C->setText(QString("C: %1").arg(barList[bar].close));
            scene->update();
            qDebug() << 3;
            if(ui->pushButtonCursor->isChecked()){
                QPen crossLine;
                crossLine.setWidth(1);
                crossLine.setColor(Qt::white);
                if(crossLine1==nullptr){
                    crossLine1 = scene->addLine(point.rx(),3,point.rx(),sceneheight-29,crossLine);
                    crossLine2 = scene->addLine(3,point.ry(),sceneWidth+1,point.ry(),crossLine);
                }else{
                    crossLine1->moveBy(point.rx()-mousePoint.rx(),0);
                    crossLine2->moveBy(0,point.ry()-mousePoint.ry());
                }
                if(rectDown!=nullptr){
                    scene->removeItem(rectDown);
                    scene->removeItem(rectRight);
                    scene->removeItem(textDown);
                    scene->removeItem(textRight);
                    delete rectDown;
                    delete rectRight;
                    delete textDown;
                    delete textRight;
                    rectDown=nullptr;
                    rectRight=nullptr;
                    textDown=nullptr;
                    textRight=nullptr;
                    scene->update();
                }
                if(rectDown==nullptr){
                    pixelsize=(maxSet-minSet)/double(sceneheight-paddingTop-paddingBottom-paddingVolume+2);
                    double currPos = maxSet +(27-point.ry())*pixelsize;

                    if (format_type==day){
                        rectDown = scene->addRect((point.rx()-25>3)?point.rx()-25:3,sceneheight-27,50,12,boxinfo,QBrush(Qt::white));
                        textDown = scene->addText(barList[bar].time.toString("yyyy.MM.dd"),font);
                    }else{
                        rectDown = scene->addRect((point.rx()-25>3)?point.rx()-25:3,sceneheight-27,60,12,boxinfo,QBrush(Qt::white));
                        textDown = scene->addText(barList[bar].time.toString("dd MMM hh:mm"),font);
                    }
                    rectRight = scene->addRect(sceneWidth+3,(point.ry()-6>3)?point.ry()-6:3,60,12,boxinfo,QBrush(Qt::white));
                    textRight = scene->addText(QString::number(currPos,'d',5),font);
                    textDown->setDefaultTextColor(Qt::black);
                    textRight->setDefaultTextColor(Qt::black);
                    textDown->moveBy((point.rx()-27>0)?point.rx()-27:1,sceneheight-30);
                    textRight->moveBy(sceneWidth+2,(point.ry()-8>0)?point.ry()-8:1);
                    rectDown->setBrush(Qt::white);
                    rectRight->setBrush(Qt::white);
                }
                if(!drawLineInCrosses && crossLine3!=nullptr){
                    scene->removeItem(crossLine3);
                    scene->removeItem(crossLine4);
                    scene->removeItem(rectDown2);
                    scene->removeItem(rectRight2);
                    scene->removeItem(textDown2);
                    scene->removeItem(textRight2);
                    scene->removeItem(lineItem);
                    scene->removeItem(crossRect);
                    scene->removeItem(crossText);
                    delete crossLine3;
                    delete crossLine4;
                    delete rectDown2;
                    delete rectRight2;
                    delete textDown2;
                    delete textRight2;
                    delete lineItem;
                    delete crossRect;
                    delete crossText;
                    crossLine3=nullptr;
                    crossLine4=nullptr;
                    rectDown2=nullptr;
                    rectRight2=nullptr;
                    textDown2=nullptr;
                    textRight2=nullptr;
                    lineItem=nullptr;
                    crossRect=nullptr;
                    crossText=nullptr;
                    scene->update();
                }
                if(drawLineInCrosses && crossLine3==nullptr){
                    int crossBar = abs(point.rx()-prevMousePoint.rx())/(barWidth+barSpace);
                    int crossPips = abs(point.ry()-prevMousePoint.ry())*pixelsize*10000;

                    double currPos = maxSet +(27-point.ry())*pixelsize;
                    crossLine3 = scene->addLine(prevMousePoint.rx(),3,prevMousePoint.rx(),sceneheight-29,crossLine);
                    crossLine4 = scene->addLine(3,prevMousePoint.ry(),sceneWidth+1,prevMousePoint.ry(),crossLine);
                    rectRight2 = scene->addRect(sceneWidth+3,(prevMousePoint.ry()-6>3)?prevMousePoint.ry()-6:3,60,12,boxinfo,QBrush(Qt::white));
                    if (format_type==day){
                        rectDown2 = scene->addRect((prevMousePoint.rx()-25>3)?prevMousePoint.rx()-25:3,sceneheight-27,50,12,boxinfo,QBrush(Qt::white));
                        textDown2 = scene->addText(barList[bar].time.toString("yyyy.MM.dd"),font);
                    }else{
                        rectDown2 = scene->addRect((prevMousePoint.rx()-25>3)?prevMousePoint.rx()-25:3,sceneheight-27,60,12,boxinfo,QBrush(Qt::white));
                        textDown2 = scene->addText(barList[bar].time.toString("dd MMM hh:mm"),font);
                    }
                    textRight2 = scene->addText(QString::number(currPos,'d',5),font);
                    textDown2->setDefaultTextColor(Qt::black);
                    textRight2->setDefaultTextColor(Qt::black);
                    textDown2->moveBy((prevMousePoint.rx()-27>0)?prevMousePoint.rx()-27:1,sceneheight-30);
                    textRight2->moveBy(sceneWidth+2,(point.ry()-8>0)?prevMousePoint.ry()-8:1);
                    lineItem = scene->addLine(prevMousePoint.rx(),prevMousePoint.ry(),mousePoint.rx(),mousePoint.ry(),crossLine);
                    crossRect = scene->addRect(point.rx()+1,point.ry()+1,80,12,QPen(QColor("#313233")),QBrush(QColor("#313233")));
                    crossText = scene->addText(QString("bars: %1, pips: %2").arg(crossBar).arg(crossPips),font);
                    crossText->setDefaultTextColor(Qt::white);
                    crossText->moveBy(point.rx(),point.ry());
                    scene->update();
                }
                if(drawLineInCrosses && crossLine3!=nullptr){
                    int crossBar = abs(point.rx()-prevMousePoint.rx())/(barWidth+barSpace);
                    int crossPips = abs(point.ry()-prevMousePoint.ry())*pixelsize*10000;
                    scene->removeItem(lineItem);
                    delete lineItem;
                    lineItem=nullptr;
                    scene->removeItem(crossRect);
                    delete crossRect;
                    crossRect=nullptr;
                    scene->removeItem(crossText);
                    delete crossText;
                    crossText=nullptr;
                    lineItem = scene->addLine(prevMousePoint.rx(),prevMousePoint.ry(),mousePoint.rx(),mousePoint.ry(),crossLine);
                    crossRect = scene->addRect(point.rx()+1,point.ry()+1,80,12,QPen(QColor("#313233")),QBrush(QColor("#313233")));
                    crossText = scene->addText(QString("bars: %1, pips: %2").arg(crossBar).arg(crossPips),font);
                    crossText->setDefaultTextColor(Qt::white);
                    crossText->moveBy(point.rx(),point.ry());
                }
                mousePoint=point;
            }
            qDebug() << 4;

            if(fibDraw && ui->pushButtonFibbonacci->isChecked()){
                if(fibbonacci!=nullptr){
                    delete fibbonacci;
                    fibbonacci=nullptr;
                }
                fibbonacci=new GraphicsItemFibbonacci(startFibbPoint,point);
                scene->addItem(fibbonacci);
            }else{
                startFibbPoint=point;
            }
            qDebug() << 5;
            scene->update();
        }else{
            qDebug() << 6;
            if(drawLineInCrosses && crossLine3!=nullptr){
                drawLineInCrosses=false;
                scene->removeItem(crossLine3);
                scene->removeItem(crossLine4);
                scene->removeItem(rectDown2);
                scene->removeItem(rectRight2);
                scene->removeItem(textDown2);
                scene->removeItem(textRight2);
                scene->removeItem(lineItem);
                scene->removeItem(crossRect);
                scene->removeItem(crossText);
                delete crossLine3;
                delete crossLine4;
                delete rectDown2;
                delete rectRight2;
                delete textDown2;
                delete textRight2;
                delete lineItem;
                delete crossRect;
                delete crossText;
                crossLine3=nullptr;
                crossLine4=nullptr;
                rectDown2=nullptr;
                rectRight2=nullptr;
                textDown2=nullptr;
                textRight2=nullptr;
                lineItem=nullptr;
                crossRect=nullptr;
                crossText=nullptr;
                scene->update();
            }
            qDebug() << 7;
            if(rectDown!=nullptr){
                scene->removeItem(rectDown);
                scene->removeItem(rectRight);
                scene->removeItem(textDown);
                scene->removeItem(textRight);
                scene->removeItem(crossLine1);
                scene->removeItem(crossLine2);
                delete rectDown;
                delete rectRight;
                delete textDown;
                delete textRight;
                delete crossLine1;
                delete crossLine2;
                rectDown=nullptr;
                rectRight=nullptr;
                textDown=nullptr;
                textRight=nullptr;
                crossLine1=nullptr;
                crossLine2=nullptr;
                scene->update();
            }
        }
}

void MainWindow::getData(QString data)
{
    {
        QFile Comp;
        int yearBegin = ui->dateFrom->date().toString("yyyy").toInt();
        int yearEnd = ui->dateTo->date().toString("yyyy").toInt();
        bezierList.clear();
        showATR=false;
        for(int curYear=yearBegin; curYear<=yearEnd; curYear++){
            qDebug() << "FILENAME=" << QString("./Docs/%1_%2_01.01.%3_31.12.%4.txt").arg(data).arg(ui->comboBox->currentText()).arg(QString::number(curYear)).arg(QString::number(curYear));
            Comp.setFileName(QString("./Docs/%1_%2_01.01.%3_31.12.%4.txt").arg(data).arg(ui->comboBox->currentText()).arg(QString::number(curYear)).arg(QString::number(curYear)));
            if(Comp.open(QIODevice::ReadOnly | QIODevice::Text)){
                while(!Comp.atEnd()){
                    QString textToSend=Comp.readLine();
                    if(textToSend.startsWith("<")){
                        continue;
                    }
                    QStringList strLine = textToSend.split("\t");
                    if(QDate::fromString(strLine.at(2),"dd/MM/yy").addYears(100)<ui->dateFrom->date()){
                        continue;
                    }
                    if(QDate::fromString(strLine.at(2),"dd/MM/yy").addYears(100)>ui->dateTo->date()){
                        break;
                    }
                    QString dateT = strLine.at(2)+" "+strLine.at(3);
                    QDateTime xTime = QDateTime::fromString(dateT,"dd/MM/yy hh:mm:ss");
                    xTime=xTime.addYears(100);

                    if(xTime.date().dayOfWeek()==6 || xTime.date().dayOfWeek()==7){continue;}
                    Bar *barX = new Bar(xTime,QString(strLine.at(4)).toDouble(),
                             QString(strLine.at(5)).toDouble(),QString(strLine.at(6)).toDouble(),QString(strLine.at(7)).toDouble(),QString(strLine.at(8)).toInt());
                    barList.push_back(*barX);
                    delete barX;
                }
            }
            Comp.close();
        }
    }
    drawGraphic();
}

void MainWindow::addLastPrice(double newClose)
{
    return;
    if(format_type==day){
        if(QDate::currentDate()==barList[barList.size()-1].time.date()){
            barList[barList.size()-1].close=newClose;
        }else{
            Bar *barX = new Bar(QDateTime::currentDateTime(),newClose,
                     newClose,newClose,newClose,0);
            barList.push_back(*barX);
            delete barX;
        }
    }else if(format_type==hour){
        if(QDateTime::currentDateTime()>=barList[barList.size()-1].time &&QDateTime::currentDateTime()<=barList[barList.size()-1].time.addSecs(3600)){
            barList[barList.size()-1].close=newClose;
        }else{
            Bar *barX = new Bar(QDateTime::currentDateTime(),newClose,
                     newClose,newClose,newClose,0);
            barList.push_back(*barX);
            delete barX;
        }
    }else if(format_type==min30){
        if(QDateTime::currentDateTime()>=barList[barList.size()-1].time &&QDateTime::currentDateTime()<=barList[barList.size()-1].time.addSecs(1800)){
            barList[barList.size()-1].close=newClose;
        }else{
            Bar *barX = new Bar(QDateTime::currentDateTime(),newClose,
                     newClose,newClose,newClose,0);
            barList.push_back(*barX);
            delete barX;
        }
    }else if(format_type==min15){
        if(QDateTime::currentDateTime()>=barList[barList.size()-1].time &&QDateTime::currentDateTime()<=barList[barList.size()-1].time.addSecs(900)){
            barList[barList.size()-1].close=newClose;
        }else{
            Bar *barX = new Bar(QDateTime::currentDateTime(),newClose,
                     newClose,newClose,newClose,0);
            barList.push_back(*barX);
            delete barX;
        }
    }else if(format_type==min1){
        if(QDateTime::currentDateTime()>=barList[barList.size()-1].time &&QDateTime::currentDateTime()<=barList[barList.size()-1].time.addSecs(60)){
            barList[barList.size()-1].close=newClose;
        }else{
            Bar *barX = new Bar(QDateTime::currentDateTime(),newClose,
                     newClose,newClose,newClose,0);
            barList.push_back(*barX);
            delete barX;
        }
    }
    ui->graphicsView->update();
}

void MainWindow::movingAverage(int average, QColor col)
{
    avColor=col;
    atrList.clear();
    if(average>barList.size())return;
    for(int i=0; i<barList.size(); i++){
        double price=0.0;
        for (int j=i-(average-1); j<=i; j++){
            if(j<0){
                price+=barList.at(i).close;
            }else{
                price+=barList.at(j).close;
            }
        }
        atrList.push_back(price/average);
    }
    delete atr;
    atr=nullptr;
    showATR=true;
    if(type==1){
        drawSceneLine(3+barWidth/2+barSpace);
    }else{
        drawSceneItems(3+barWidth/2+barSpace);
    }
}

void MainWindow::drawRedRect()
{
    //----------------------------------------------------Рисуем красный квадрат текущей цены-------------------------------------------------
    //Рисуем красный квадрат справа с текущей ценой
    double curPrice = barList[barList.size()-1].close;
    pixelsize=(maxSet-minSet)/double(sceneheight-30-70);
    double begin = minSet-pixelsize*43;
    double diff = (curPrice-begin)/pixelsize;
    if(curPrice>=minSet && curPrice<=maxSet){
        rectRightPrice = scene->addRect(sceneWidth+7,sceneheight-28-5-diff,50,12,boxinfo,QBrush(Qt::red));
        scene->addLine(sceneWidth+2,sceneheight-27-diff,sceneWidth+6,sceneheight-27-diff,QPen(QColor(Qt::white)));
        rectRightPrice->setBrush(Qt::red);
        textRightPrice = scene->addText(QString::number(curPrice,'d',5),font);
        textRightPrice->setDefaultTextColor(Qt::white);
        textRightPrice->moveBy(sceneWidth+6,sceneheight-28-8-diff);
    }else if(curPrice<minSet){
        rectRightPrice = scene->addRect(sceneWidth+7,sceneheight-33,50,12,boxinfo,QBrush(Qt::red));
        scene->addLine(sceneWidth+2,sceneheight-28,sceneWidth+6,sceneheight-28,QPen(QColor(Qt::white)));
        rectRightPrice->setBrush(Qt::red);
        textRightPrice = scene->addText(QString::number(curPrice,'d',5),font);
        textRightPrice->setDefaultTextColor(Qt::white);
        textRightPrice->moveBy(sceneWidth+6,sceneheight-36);
    }

}

void MainWindow::drawGraphic()
{
    //----------------------------------------------------Рисуем график-------------------------------------------------
        mousePoint=QPointF(0,0);
        pen.setColor(Qt::white);
        pen.setWidth(0.1);
        brush1.setStyle(Qt::SolidPattern);
        penLine.setStyle(Qt::DashLine);
        penLine.setColor(QColor(183,219,255));
        penLine.setWidth(1);
        ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);                        // Делаем привязку содержимого к центру
        ui->graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету
        this->setFocus();
        font.setPointSize(7);               //Устанавливаем размер шрифта для оси У
        fontInfo.setPointSize(7);
        penCandel.setWidth(0);
        netPen.setColor(QColor("#836033"));     //Ручка для сетки
        netPen.setWidth(0);
        netPen.setStyle(Qt::DashLine);          //Пунктиром
        QBrush burhInfo(Qt::white);
        boxinfo.setBrush(burhInfo);
        barWidth=barWidthList[barIndex];        //Устанавливаем толщину свечи согласно дефолтному индексу
        barSpace=barSpaceList[barIndex];        //Устанавливаем пробел между свечами согласно дефолтному индексу
        this->setAttribute(Qt::WA_NoMousePropagation);
        signalForStart=true;
        sceneWidth=ui->widget->width()-70;
        sceneheight=ui->widget->height()-2;
        barPos=0;
        if(barPos+(sceneWidth)/(barWidth+barSpace)>barList.size()){
            graphEnd=true;
            barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
        }
        if(graphEnd){
            barPos=barList.size()-(sceneWidth)/(barWidth+barSpace);
        }
        if(type==1){
            drawSceneLine(3+barWidth/2+barSpace);
        }else{
            drawSceneItems(3+barWidth/2+barSpace);
        }
        //----------------------------------------------------------------------------------------------------------------------------
}

void MainWindow::setTitle()
{

}
