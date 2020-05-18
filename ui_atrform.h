/********************************************************************************
** Form generated from reading UI file 'atrform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATRFORM_H
#define UI_ATRFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AtrForm
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEditATR;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *buttonLoad;

    void setupUi(QWidget *AtrForm)
    {
        if (AtrForm->objectName().isEmpty())
            AtrForm->setObjectName(QString::fromUtf8("AtrForm"));
        AtrForm->resize(317, 52);
        gridLayout = new QGridLayout(AtrForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEditATR = new QLineEdit(AtrForm);
        lineEditATR->setObjectName(QString::fromUtf8("lineEditATR"));
        lineEditATR->setInputMethodHints(Qt::ImhPreferNumbers);

        gridLayout->addWidget(lineEditATR, 0, 1, 1, 1);

        pushButton = new QPushButton(AtrForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(23, 23));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 255, 46);"));
        pushButton->setFlat(false);

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        label = new QLabel(AtrForm);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonLoad = new QPushButton(AtrForm);
        buttonLoad->setObjectName(QString::fromUtf8("buttonLoad"));

        gridLayout->addWidget(buttonLoad, 0, 3, 1, 1);


        retranslateUi(AtrForm);

        QMetaObject::connectSlotsByName(AtrForm);
    } // setupUi

    void retranslateUi(QWidget *AtrForm)
    {
        AtrForm->setWindowTitle(QApplication::translate("AtrForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\200\320\265\320\264\320\275\321\216\321\216 \321\201\320\272\320\276\320\273\321\214\320\267\321\217\321\211\321\203\321\216", nullptr));
        pushButton->setText(QString());
        label->setText(QApplication::translate("AtrForm", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217 \321\201\320\272\320\276\320\273\321\214\320\267\321\217\321\211\320\260\321\217", nullptr));
        buttonLoad->setText(QApplication::translate("AtrForm", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AtrForm: public Ui_AtrForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATRFORM_H
