#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QSqlQueryModel>
#include <QTextStream>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>

SearchDialog::SearchDialog(QWidget *parent, QSqlDatabase *dbConn) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    this->dbConn = dbConn;

    // Set table view
    model = new QSqlQueryModel(this);
    model->setQuery("select date, getup, anniversary, birth, fate, meet, specialDate, "
                    "field1, field2, field3, field4, field5, field6, "
                    "field7, field8 from diary", dbConn->database());

    model->setHeaderData(0, Qt::Horizontal, "日期");
    model->setHeaderData(1, Qt::Horizontal, "起床");
    model->setHeaderData(2, Qt::Horizontal, "紀念日");
    model->setHeaderData(3, Qt::Horizontal, "生日");
    model->setHeaderData(4, Qt::Horizontal, "命運之日");
    model->setHeaderData(5, Qt::Horizontal, "邂逅");
    model->setHeaderData(6, Qt::Horizontal, "什麼日子");
    model->setHeaderData(7, Qt::Horizontal, "成功日記");
    model->setHeaderData(8, Qt::Horizontal, "人生的夢/興趣");
    model->setHeaderData(9, Qt::Horizontal, "家庭");
    model->setHeaderData(10, Qt::Horizontal, "金錢");
    model->setHeaderData(11, Qt::Horizontal, "健康");
    model->setHeaderData(12, Qt::Horizontal, "人際");
    model->setHeaderData(13, Qt::Horizontal, "感情");
    model->setHeaderData(14, Qt::Horizontal, "工作/學習");

    ui->tableView->setModel(model);
    ui->tableView->show();
}

void SearchDialog::setDate(QDate *date)
{
    this->selectedDate = date;
}

SearchDialog::~SearchDialog()
{
    delete ui;
}


void SearchDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString str = model->data( model->index(index.row(), 0 ) ).toString();
    int y = str.mid(0,4).toInt();
    int m = str.mid(4,2).toInt();
    int d = str.mid(6,2).toInt();
    this->selectedDate = new QDate(y,m,d);
    emit done(y,m,d);
    this->close();
}
