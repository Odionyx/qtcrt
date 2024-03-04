#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    timer->setInterval(94);

    time_s = time_ms = time_s2 = time_ms2 = 0;
    circle =  count = temp = temp2 = 0;
    checked = true;

    connect(timer, &QTimer::timeout, this, [&]{
        count++;
        time_ms = count % 10;
        time_s  = count / 10;
        emit sig_timer(&time_s, &time_ms);
    }, Qt::QueuedConnection);
}

Stopwatch::~Stopwatch()
{
    delete timer;
}

void Stopwatch::slot_start(bool checked)
{
    if(checked){
        timer->start();
    } else {
        timer->stop();
    }
}

void Stopwatch::slot_circle()
{
    circle++;

    temp = count - temp2;
    temp2 = count;

    time_ms2 = temp % 10;
    time_s2  = temp / 10;

    emit sig_result(&circle, &time_s2, &time_ms2);
}

void Stopwatch::slot_clear()
{
    timer->stop();
    time_s = time_ms = time_s2 = time_ms2 = 0;
    circle =  count = temp = temp2 = 0;
    emit sig_timer(&time_s, &time_ms);
}
