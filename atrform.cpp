#include "atrform.h"
#include "ui_atrform.h"
#include <QDebug>

AtrForm::AtrForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AtrForm)
{
    ui->setupUi(this);
    col=QColor(252, 255, 46);
    connect(ui->pbLoad,&QPushButton::clicked,[=]{
        if(ui->lineEditATR->text().toInt()==0)return;
        emit createAverageLine(ui->lineEditATR->text().toInt(),col);
    });
    connect(ui->pbColor,&QPushButton::clicked,[=]{
        QColorDialog * dial = new QColorDialog(this);
        dial->show();
        connect(dial,&QColorDialog::colorSelected,[=](QColor color){
            col=color;
            ui->pbColor->setStyleSheet(QString("QPushButton{"
                                              "background-color: %1;"
                                              "border-radius: 12px;}").arg(col.name()));
        });

    });
    connect(ui->pbCancel,&QPushButton::clicked,[=]{
        this->close();
    });
}

AtrForm::~AtrForm()
{
    delete ui;
}
