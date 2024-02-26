#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Name */
    ui->radioButton->setText("Вкл.");
    ui->radioButton_2 ->setText("Выкл.");
    ui->groupBox->setTitle("Соединение");

    /* drop list */
    ui->comboBox->addItem("Создать");
    ui->comboBox->addItem("Добавить столбец");
    ui->comboBox->addItem("Добавить строку");
    ui->comboBox->addItem("Удалить строку");
    ui->comboBox->addItem("Удалить столбец");
    ui->comboBox->addItem("Удалить");

    // Create the button, make "this" the parent
    m_button = new QPushButton("Выполнить", this);
    // set size and location of the button
    m_button->setGeometry(QRect(QPoint(10, 10), QSize(200, 50)));
//    m_button->setChecked(true);

    //Ещё не разобрался как кнопку в другое место экрана поставить
    //Connect button for main
    setMenuWidget(m_button);
    // Connect button signal to appropriate slot
    connect(m_button, &QPushButton::clicked, this, &MainWindow::on_pushButton_toggled, Qt::UniqueConnection);

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
//    qDebug() << " qDebug(checked): " << checked;
    if((ui->spinBox->value())< 10){
        ui->spinBox->setValue((ui->spinBox->value())+1);
    }else {ui->spinBox->setValue(0);}
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
