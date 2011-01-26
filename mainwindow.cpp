#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionUrDiary_triggered()
{
    //Show "about dialog"
    AboutWindow about;
    about.show();
}
