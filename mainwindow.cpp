#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
QSerialPort *serial;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial=new QSerialPort(this);
    serial.setPortName("com3");
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);
    serial.write("ok");
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialRecieved()));


}

MainWindow::~MainWindow()
{
    delete ui;
    serial.close();
}
void MainWindow::serialRecieved()
{
    ui->label->setText(serial->readAll());
}

