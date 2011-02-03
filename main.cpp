#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Detect user home path
    QString path = QDir::homePath();

    // Find DB and build new DB if not found
    QFile *db = new QFile(path + "urDiary.db");
    if( db->exists() == false ){
        if( QMessageBox::question(NULL,"DB", "DB not Found \nBuild a new one ?"
                                  ,QMessageBox::Yes,QMessageBox::No) == true ){
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
