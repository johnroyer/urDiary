#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set text codec
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "UTF-8" ) );
    QTextCodec::setCodecForTr( QTextCodec::codecForName( "UTF-8" ) );

    // Detect user home path
    QString path = QDir::homePath();
    QString dbPath = path + "/urDiary.db";

    // Find DB and build new DB if not found
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( dbPath );

    if( !db.open() ){
        QMessageBox::critical(0,"Can not open database"
                              ,"Unable to establish a database connection."
                              ,QMessageBox::Ok);
        return false;
    }

    QSqlQuery query(db);
    MainWindow w;
    w.setDbQuery(&query);
    w.show();

    return a.exec();
}
