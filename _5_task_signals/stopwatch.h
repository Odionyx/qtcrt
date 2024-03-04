#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

signals:
    void sig_timer(int*, int*);
    void sig_result(int*, int*, int*);

public slots:
    void slot_start(bool checked);
    void slot_circle();
    void slot_clear();

private:
    QTimer *timer;
    int circle, time_s, time_ms, time_s2, time_ms2;
    long int count, temp, temp2;
    bool checked;

};

#endif // STOPWATCH_H
