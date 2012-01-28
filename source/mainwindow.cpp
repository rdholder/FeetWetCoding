// copyright (c) 2011 eotsucodefoundry.com.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include <setup.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearScreen()
{
    cerr << "mainwindow::clearScreen()\n";
    QPen pen(Qt::black, 20, Qt::SolidLine);

    QPainter painter(this);

    painter.setPen(pen);
    painter.drawLine(20, 40, 250, 40);

//    int x1, y1, x2, y2;
//    mainWindow->centralWidget()->geometry().getCoords(&x1, &y1, &x2, &y2);
//    cerr << "mainWindow->centralWidget()->geometry(): "<<x1<<","<<y1<<","<<x2<<","<<y2<< std::endl;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    return;

    cerr << "mainwindow::paintEvent()\n";
    QPen pen(Qt::black, 2, Qt::SolidLine);

    QPainter painter(this);

    painter.setPen(pen);
    painter.drawLine(20, 40, 250, 40);

    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    painter.drawLine(20, 80, 250, 80);

    pen.setStyle(Qt::DashDotLine);
    painter.setPen(pen);
    painter.drawLine(20, 120, 250, 120);

    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);
    painter.drawLine(20, 160, 250, 160);

    pen.setStyle(Qt::DashDotDotLine);
    painter.setPen(pen);
    painter.drawLine(20, 200, 250, 200);

    QVector<qreal> dashes;
    qreal space = 4;

    dashes << 1 << space << 5 << space;

    pen.setStyle(Qt::CustomDashLine);
    pen.setDashPattern(dashes);
    painter.setPen(pen);
    painter.drawLine(20, 240, 250, 240);
}
