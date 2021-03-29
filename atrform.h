#ifndef ATRFORM_H
#define ATRFORM_H

#include <QWidget>
#include <QColorDialog>
#include <QColor>
#include <QDebug>

namespace Ui {
class AtrForm;
}

class AtrForm : public QWidget
{
    Q_OBJECT
    QColor col;
public:
    explicit AtrForm(QWidget *parent = nullptr);
    ~AtrForm();

private:
    Ui::AtrForm *ui;
signals:
    void createAverageLine(int,QColor);
    void canceled();
};

#endif // ATRFORM_H
