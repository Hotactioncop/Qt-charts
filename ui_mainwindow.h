/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboName;
    QPushButton *pushButtonATR;
    QPushButton *pushButtonCursor;
    QPushButton *pushButtonArrow;
    QPushButton *pushButtonCandle;
    QPushButton *pushButtonLine;
    QPushButton *pushButtonBar;
    QPushButton *pushButtonVolume;
    QPushButton *pushButtonVolume_2;
    QCheckBox *checkBoxNet;
    QPushButton *pushButtonFibbonacci;
    QLabel *label;
    QComboBox *comboBox;
    QDateEdit *dateFrom;
    QDateEdit *dateTo;
    QPushButton *LoadButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(905, 486);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/bar-chart1.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboName = new QComboBox(centralWidget);
        comboName->addItem(QString());
        comboName->addItem(QString());
        comboName->addItem(QString());
        comboName->setObjectName(QString::fromUtf8("comboName"));

        horizontalLayout->addWidget(comboName);

        pushButtonATR = new QPushButton(centralWidget);
        pushButtonATR->setObjectName(QString::fromUtf8("pushButtonATR"));
        pushButtonATR->setMaximumSize(QSize(28, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/atrchart.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonATR->setIcon(icon1);
        pushButtonATR->setIconSize(QSize(24, 24));
        pushButtonATR->setCheckable(false);
        pushButtonATR->setFlat(true);

        horizontalLayout->addWidget(pushButtonATR);

        pushButtonCursor = new QPushButton(centralWidget);
        pushButtonCursor->setObjectName(QString::fromUtf8("pushButtonCursor"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(32);
        sizePolicy.setVerticalStretch(32);
        sizePolicy.setHeightForWidth(pushButtonCursor->sizePolicy().hasHeightForWidth());
        pushButtonCursor->setSizePolicy(sizePolicy);
        pushButtonCursor->setMaximumSize(QSize(28, 28));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/target.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCursor->setIcon(icon2);
        pushButtonCursor->setIconSize(QSize(24, 24));
        pushButtonCursor->setCheckable(true);
        pushButtonCursor->setFlat(true);

        horizontalLayout->addWidget(pushButtonCursor);

        pushButtonArrow = new QPushButton(centralWidget);
        pushButtonArrow->setObjectName(QString::fromUtf8("pushButtonArrow"));
        pushButtonArrow->setMaximumSize(QSize(28, 28));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/arrow.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonArrow->setIcon(icon3);
        pushButtonArrow->setIconSize(QSize(24, 24));
        pushButtonArrow->setCheckable(true);
        pushButtonArrow->setChecked(true);
        pushButtonArrow->setFlat(true);

        horizontalLayout->addWidget(pushButtonArrow);

        pushButtonCandle = new QPushButton(centralWidget);
        pushButtonCandle->setObjectName(QString::fromUtf8("pushButtonCandle"));
        pushButtonCandle->setMaximumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/barchart.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCandle->setIcon(icon4);
        pushButtonCandle->setIconSize(QSize(24, 24));
        pushButtonCandle->setCheckable(true);
        pushButtonCandle->setChecked(true);
        pushButtonCandle->setFlat(true);

        horizontalLayout->addWidget(pushButtonCandle);

        pushButtonLine = new QPushButton(centralWidget);
        pushButtonLine->setObjectName(QString::fromUtf8("pushButtonLine"));
        pushButtonLine->setMaximumSize(QSize(32, 32));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Images/linechart.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonLine->setIcon(icon5);
        pushButtonLine->setIconSize(QSize(24, 24));
        pushButtonLine->setCheckable(true);
        pushButtonLine->setFlat(true);

        horizontalLayout->addWidget(pushButtonLine);

        pushButtonBar = new QPushButton(centralWidget);
        pushButtonBar->setObjectName(QString::fromUtf8("pushButtonBar"));
        pushButtonBar->setMaximumSize(QSize(32, 32));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../Charts/Images/barchart2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonBar->setIcon(icon6);
        pushButtonBar->setIconSize(QSize(24, 24));
        pushButtonBar->setCheckable(true);
        pushButtonBar->setFlat(true);

        horizontalLayout->addWidget(pushButtonBar);

        pushButtonVolume = new QPushButton(centralWidget);
        pushButtonVolume->setObjectName(QString::fromUtf8("pushButtonVolume"));
        pushButtonVolume->setMaximumSize(QSize(32, 32));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Images/volume.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonVolume->setIcon(icon7);
        pushButtonVolume->setIconSize(QSize(24, 24));
        pushButtonVolume->setCheckable(true);
        pushButtonVolume->setFlat(true);

        horizontalLayout->addWidget(pushButtonVolume);

        pushButtonVolume_2 = new QPushButton(centralWidget);
        pushButtonVolume_2->setObjectName(QString::fromUtf8("pushButtonVolume_2"));
        pushButtonVolume_2->setMaximumSize(QSize(32, 32));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Images/volume2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonVolume_2->setIcon(icon8);
        pushButtonVolume_2->setIconSize(QSize(24, 24));
        pushButtonVolume_2->setCheckable(true);
        pushButtonVolume_2->setFlat(true);

        horizontalLayout->addWidget(pushButtonVolume_2);

        checkBoxNet = new QCheckBox(centralWidget);
        checkBoxNet->setObjectName(QString::fromUtf8("checkBoxNet"));

        horizontalLayout->addWidget(checkBoxNet);

        pushButtonFibbonacci = new QPushButton(centralWidget);
        pushButtonFibbonacci->setObjectName(QString::fromUtf8("pushButtonFibbonacci"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Images/fibbonacci.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonFibbonacci->setIcon(icon9);
        pushButtonFibbonacci->setCheckable(true);
        pushButtonFibbonacci->setFlat(true);

        horizontalLayout->addWidget(pushButtonFibbonacci);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        dateFrom = new QDateEdit(centralWidget);
        dateFrom->setObjectName(QString::fromUtf8("dateFrom"));
        dateFrom->setDateTime(QDateTime(QDate(2019, 1, 1), QTime(0, 0, 0)));
        dateFrom->setMaximumDate(QDate(2019, 12, 31));
        dateFrom->setMinimumDate(QDate(2017, 1, 1));
        dateFrom->setCalendarPopup(true);

        horizontalLayout->addWidget(dateFrom);

        dateTo = new QDateEdit(centralWidget);
        dateTo->setObjectName(QString::fromUtf8("dateTo"));
        dateTo->setDateTime(QDateTime(QDate(2019, 12, 31), QTime(0, 0, 0)));
        dateTo->setMaximumDate(QDate(2019, 12, 31));
        dateTo->setMinimumDate(QDate(2017, 1, 1));
        dateTo->setCalendarPopup(true);

        horizontalLayout->addWidget(dateTo);

        LoadButton = new QPushButton(centralWidget);
        LoadButton->setObjectName(QString::fromUtf8("LoadButton"));

        horizontalLayout->addWidget(LoadButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(graphicsView);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 905, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        comboName->setCurrentIndex(1);
        comboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Charts", nullptr));
        comboName->setItemText(0, QString());
        comboName->setItemText(1, QApplication::translate("MainWindow", "America Express", nullptr));
        comboName->setItemText(2, QApplication::translate("MainWindow", "3M", nullptr));

#ifndef QT_NO_TOOLTIP
        pushButtonATR->setToolTip(QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217 \321\201\320\272\320\276\320\273\321\214\320\267\321\217\321\211\320\260\321\217", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonATR->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonCursor->setToolTip(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\272\321\203\321\200\321\201\320\276\321\200", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonCursor->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonArrow->setToolTip(QApplication::translate("MainWindow", "\320\241\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\320\271 \320\272\321\203\321\200\321\201\320\276\321\200", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonArrow->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonCandle->setToolTip(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\257\320\277\320\276\320\275\321\201\320\272\320\270\320\265 \321\201\320\262\320\265\321\207\320\270", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonCandle->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonLine->setToolTip(QApplication::translate("MainWindow", "\320\233\320\270\320\275\320\265\320\271\320\275\321\213\320\271 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonLine->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonBar->setToolTip(QApplication::translate("MainWindow", "\320\221\320\260\321\200\320\275\321\213\320\271 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonBar->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonVolume->setToolTip(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\276\320\261\321\212\320\265\320\274\320\276\320\262", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonVolume->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonVolume_2->setToolTip(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\276\320\261\321\212\320\265\320\274\320\276\320\262 2", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonVolume_2->setText(QString());
        checkBoxNet->setText(QApplication::translate("MainWindow", "\320\241\320\272\321\200\321\213\321\202\321\214 \321\201\320\265\321\202\320\272\321\203", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonFibbonacci->setToolTip(QApplication::translate("MainWindow", "\320\233\320\270\320\275\320\270\320\270 \320\244\320\270\320\261\320\261\320\276\320\275\320\260\321\207\320\270", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonFibbonacci->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202", nullptr));
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QApplication::translate("MainWindow", "1M", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "15M", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "30M", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "H", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "D", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "W", nullptr));
        comboBox->setItemText(7, QApplication::translate("MainWindow", "M", nullptr));

        LoadButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
