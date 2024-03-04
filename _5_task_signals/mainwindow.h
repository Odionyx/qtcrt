#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QDebug>
#include <QMainWindow>
#include "stopwatch.h"
#include <QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sig_start(bool);
    void sig_clear(bool);
    void sig_circle();

public slots:
    void slot_l_timer(int*, int*);

private slots:
    void slot_pB_start_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    Stopwatch *watch;

};
#endif // MAINWINDOW_H
