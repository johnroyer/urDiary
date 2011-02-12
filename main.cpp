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
    QString path = QDir::homePath() + "/";
    QString dbPath = path + "urDiary.db";
    dbPath = QDir::toNativeSeparators(dbPath);
//    QMessageBox::about(0,"123",dbPath);

    // Find DB and build new DB if not found
    QFile file(dbPath);
    bool dbExist = true;
    if( !file.exists() ){
        dbExist = false;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( dbPath );

    if( !db.open() ){
        QMessageBox::critical(0,"Can not open database"
                              ,"Unable to establish a database connection."
                              ,QMessageBox::Ok);
        return false;
    }

    QSqlQuery query(db);

    // DB initialize
    if( dbExist == false ){
        query.exec("create table diary ("
                "id integer primary key AUTOINCREMENT,"
                "date text, "
                "field1 text, "
                "field2 text, "
                "field3 text, "
                "field4 text, "
                "field5 text, "
                "field6 text, "
                "field7 text, "
                "field8 text, "
                "anniversary text, "
                "birth text, "
                "fate text, "
                "meet text, "
                "specialDate text, "
                "weather text, "
                "getup text )");
        query.exec("create table sys ( "
                "id integer primary key AUTOINCREMENT, "
                "var text, "
                "val text )");
        bool result = query.exec("insert into sys (var, val) values('dbversion','1')");
        result = query.exec("insert into sys (var, val) values('start','"
                + QDate::currentDate().toString("yyyyMMdd") +
                "')");
    }

    MainWindow w;
    w.setDbQuery(&query);
    w.initForm();
    w.show();

    return a.exec();
}
