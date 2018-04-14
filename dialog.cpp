#include "dialog.h"
#include "ui_dialog.h"
//#include <QPainter>
//#include<ui_qpainter.h>
//#include <qpainter.h>
//#include <QtPrintSupport/QPrinter>
//#include <QtPrintSupport/QPrintDialog>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;

}
void Dialog::paint(QPaintEvent *){
QPainter painter(this);
painter.drawLine(10,10,1000,1000);
}
