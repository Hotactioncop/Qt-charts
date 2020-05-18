#include "atrform.h"
#include "ui_atrform.h"

AtrForm::AtrForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AtrForm)
{
    ui->setupUi(this);
    qDebug() << "CALLED";
    col=QColor(252, 255, 46);
    connect(ui->buttonLoad,&QPushButton::clicked,[=]{
        if(ui->lineEditATR->text().toInt()==0)return;
        emit createAverageLine(ui->lineEditATR->text().toInt(),col);
    });
    connect(ui->pushButton,&QPushButton::clicked,[=]{
        QColorDialog * dial = new QColorDialog(this);
        dial->show();
        connect(dial,&QColorDialog::colorSelected,[=](QColor color){
            col=color;
            ui->pushButton->setStyleSheet(QString("background-color: %1").arg(col.name()));
        });

    });
}

AtrForm::~AtrForm()
{
    delete ui;
}
