#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Progress bard */

    ui->progressBar->setMaximum(10);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_toggled(bool checked)
{
    int count = ui->spinBox->value();
    if(count>9){
        count=-1;
    }
    ui->spinBox->setValue(++count);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->progressBar->setValue(arg1);
}

void MainWindow::on_progressBar_valueChanged(int value)
{
    if(value==0){
        ui->radioButton_2->animateClick();
    }
}

