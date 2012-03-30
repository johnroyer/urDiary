#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QSqlQueryModel>
#include <QTextStream>
#include <QSqlError>

SearchDialog::SearchDialog(QWidget *parent, QSqlDatabase *dbConn) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    this->dbConn = dbConn;


    // Set table view
    model = new QSqlQueryModel(this);
    model->setQuery("select * from diary", dbConn->database());
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "日期");
    model->setHeaderData(2, Qt::Horizontal, "成功日記");
    model->setHeaderData(3, Qt::Horizontal, "人生的夢/興趣");
    model->setHeaderData(4, Qt::Horizontal, "家庭");
    model->setHeaderData(5, Qt::Horizontal, "金錢");
    model->setHeaderData(6, Qt::Horizontal, "健康");
    model->setHeaderData(7, Qt::Horizontal, "人際");
    model->setHeaderData(8, Qt::Horizontal, "感情");
    model->setHeaderData(9, Qt::Horizontal, "工作/學習");
    model->setHeaderData(10, Qt::Horizontal, "紀念日");
    model->setHeaderData(11, Qt::Horizontal, "生日");
    model->setHeaderData(12, Qt::Horizontal, "命運之日");
    model->setHeaderData(13, Qt::Horizontal, "邂逅");
    model->setHeaderData(14, Qt::Horizontal, "什麼日子");
    model->setHeaderData(15, Qt::Horizontal, "天氣");
    model->setHeaderData(16, Qt::Horizontal, "起床");

    ui->tableView->setModel(model);
    ui->tableView->show();
}

SearchDialog::~SearchDialog()
{
    delete ui;
}


void SearchDialog::on_pushButton_clicked()
{

}
