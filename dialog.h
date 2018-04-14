#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include<QtCore>
//#include <QtWidgets>
//#include <qpainter.h>
//#include <Qtcore>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
protected:
    void paint(QPaintEvent *e);
};

#endif // DIALOG_H
