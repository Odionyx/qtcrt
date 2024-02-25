#include <QCoreApplication>
#include <QtNetwork/QtNetwork>
#include <QtSql/QtSql>

class SQL {
    char* DatabaseName[24];
    char* UserName[24];
    char* Password[24];
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHostAddress ha = QHostAddress::LocalHost;

    try {
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.port();
        db.setDatabaseName("dvdrental");
        db.setUserName("postgres");
        db.setPassword("postgres");
        if (!db.open()) {
            qDebug() << db.isOpenError();  //....
        }
    } catch (const QSqlError e) {
         qDebug() << "Error connect db:" << QDate::currentDate();
    }

    return a.exec();
}
