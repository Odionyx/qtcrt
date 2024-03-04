#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    watch = new Stopwatch(this);

    ui->pB_start->setText("  Старт  ");
    ui->pB_clear->setText("Очистить");
    ui->pB_circle->setText("Круг");
    ui->l_time->setText("Время");

    ui->pB_circle->blockSignals(true);
    ui->pB_clear->blockSignals(false);

    connect(ui->pB_start, &QAbstractButton::clicked, this, &MainWindow::slot_pB_start_toggled);
    connect(ui->pB_start, &QAbstractButton::clicked, watch, &Stopwatch::slot_start);
    connect(ui->pB_clear, &QAbstractButton::released,watch, &Stopwatch::slot_clear);
    connect(ui->pB_circle,&QAbstractButton::pressed, watch,&Stopwatch::slot_circle);

    connect(watch, &Stopwatch::sig_result, this, [&](int* circle, int* s, int* ms){
        ui->tB_result->append( "«Круг " + (QString::number(*circle)) + ", время: " +
            (QString::number(*s)) + "." + (QString::number(*ms)) + " сек»");},Qt::QueuedConnection);

    connect(watch, &Stopwatch::sig_timer, this, &MainWindow::slot_l_timer, Qt::UniqueConnection);

}

MainWindow::~MainWindow()
{
    delete watch;
    delete ui;
}

void MainWindow::slot_l_timer(int *s, int *ms)
{
    ui->l_time->setText((QString::number(*s)) + ":" + (QString::number(*ms)));
}

void MainWindow::slot_pB_start_toggled(bool checked)
{
    if(checked){
        ui->pB_start->setText("  Стоп   ");
        ui->pB_circle->blockSignals(!checked);
        ui->pB_clear->blockSignals(checked);
    } else {
        ui->pB_start->setText("  Старт  ");
        ui->pB_circle->blockSignals(!checked);
        ui->pB_clear->blockSignals(checked);
    }
}

/*
//Qt::AutoConnection: //Если в одном потоке сиг/слот то Direct если в разных то QueuedConnection
                      по умолчанию, определяется автоматически при генерации сигнала.
//                    Если и отправитель, и получатель находятся в одном потоке, то используется
//                    Qt::DirectConnection, иначе применяется Qt::QueuedConnection.

//Qt::DirectConnection: //Слот вызывается сразу
                      в этом случае и сигнал, и слот находятся в одном потоке.
//                    Слот вызывается сразу после генерации сигнала.

//Qt::QueuedConnection: //Сигнал ставится в цикл обработки событий
                      в этом случае слот находится в разных потоках.
//                    Слот вызывается, как только управление возвращается в цикл
//                    обработки событий потока получателя.

//Qt::BlockingQueuedConnection: //Блокирует поток
                      аналогичен Qt::QueuedConnection за тем исключением,
//                    что поток сигнала блокируется до тех пор, пока слот не будет выполнен.
//                    Это соединение нельзя использовать, если отправитель и получатель
//                    находятся в одном потоке, чтобы избежать взаимоблокировки.

//Qt::UniqueConnection: //0x80,
                      его можно комбинировать с любым из вышеупомянутых типов соединения,
//                    используя побитовую операцию ИЛИ. Применяется, чтобы избежать дублирования
//                    соединений. Соединение завершится неудачно, если оно уже существует.

//Qt::SingleShotConnection: 0x100,
                      одноразовая обработка сигнала. В этом случае слот вызывается только
//                    один раз, и соединение разрывается после генерации сигнала. Данный тип можно
//                    использовать с другими типами соединений. Этот тип соединения был добавлен в Qt 6.0.


// Output Date time

// QString text = QTime(0,0,*s, *ms).toString("hh:mm:ss:zzz");

// ui->statusbar->showMessage(QDateTime::currentDateTime().toString());
*/



