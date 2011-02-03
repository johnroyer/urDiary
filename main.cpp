#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Set text codec
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "UTF-8" ) );
    QTextCodec::setCodecForTr( QTextCodec::codecForName( "UTF-8" ) );

    // Detect user home path
    QString path = QDir::homePath();

    // Find DB and build new DB if not found
    QFile *db = new QFile(path + "urDiary.db");
    if( db->exists() == false ){
        if( QMessageBox::question(NULL,"DB", "DB not Found \nBuild a new one ?"
                                  ,QMessageBox::Yes
                                  ,QMessageBox::No) == QMessageBox::Yes  ){
            // Create DB
        }else{
            QMessageBox::about(NULL, "Oops", "See you");
            return 1;
        }
    }else{
        // Open DB to read
    }

    w.show();

    return a.exec();
}
