#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QDebug>

void Dialog::get_values(){
    query= QSqlQuery(db);
    QTableWidgetItem *item;
    item = new QTableWidgetItem();
    query.prepare("exec select_workers :age, :skills, :position");
    query.bindValue(":age", age);
    query.bindValue(":skills", experinces);
    query.bindValue(":position", position);
    query.exec();
    query.next();
    ui->tableWidget->setItem(0, 1, item);
    qDebug()<<age<<experinces<<position<<query.value(0);
    QString name = query.value(0).toString();
     ui->tableWidget->item(0, 1)->setText(name);
     query.prepare("exec get_age :worker_name");
     query.bindValue(":worker_name", name);
     query.exec();
     query.next();
     item = new QTableWidgetItem();
     ui->tableWidget->setItem(1, 1, item);
     QString age_bd = query.value(0).toString();
     ui->tableWidget->item(1, 1)->setText(age_bd);
     query.prepare("exec get_login :worker_name");
     query.bindValue(":worker_name", name);
     query.exec();
     query.next();
     QString login = query.value(0).toString();
     query.prepare("exec get_education :worker_login");
     query.bindValue(":worker_login", login);
     query.exec();
     query.next();
     item = new QTableWidgetItem();
     ui->tableWidget->setItem(2, 1, item);
     QString education=query.value(0).toString();
     ui->tableWidget->item(2, 1)->setText(education);
     query.prepare("exec get_position :worker_name");
     query.bindValue(":worker_name", name);
     query.exec();
     query.next();
     item = new QTableWidgetItem();
     ui->tableWidget->setItem(3, 1, item);
     QString position_bd =query.value(0).toString();
     ui->tableWidget->item(3, 1)->setText(position_bd);
     query.prepare("exec get_score :worker_login");
     query.bindValue(":worker_login", login);
     query.exec();
     query.next();
     item = new QTableWidgetItem();
     ui->tableWidget->setItem(4, 1, item);
     QString score =query.value(0).toString();
     ui->tableWidget->item(4, 1)->setText(score);
     query.prepare("exec get_competence :worker_login");
     query.bindValue(":worker_login", login);
     query.exec();
     query.next();
     item = new QTableWidgetItem();
     ui->tableWidget->setItem(5, 1, item);
     QString compitience =query.value(1).toString();
     ui->tableWidget->item(5, 1)->setText(compitience);
     item = new QTableWidgetItem();
     ui->tableWidget->setItem(6, 1, item);
     QString guide =query.value(0).toString();
     ui->tableWidget->item(6, 1)->setText(guide);
}

Dialog::Dialog(int age1, QString experinces1, QString position1, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QODBC3");

    db.setDatabaseName("DRIVER={SQL Server Native Client 11.0};SERVER=localhost\\SQLExpress01;DATABASE=workers;Trusted_connection=yes");

    if (!db.open()){
        QMessageBox::critical(this, "Ошибка", "Не удалось подключться к базе данных");
    }
    age = age1;
    experinces = experinces1;
    position=position1;
   this->get_values();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_change_Button_clicked()
{
    QString new_item, name;
    QTableWidgetItem *item = ui->tableWidget->item(4,1);
    if (NULL != item) {
       new_item = item->text();
    }
    item = ui->tableWidget->item(0,1);
    name = item->text();
    query.prepare("exec change_score :worker_name, :new_score");
    query.bindValue(":worker_name", name);
    query.bindValue(":new_score", new_item);
    query.exec();
    item = ui->tableWidget->item(6,1);
    new_item = item->text();
    query.prepare("exec change_guide :worker_name, :new_guide");
    query.bindValue(":worker_name", name);
    query.bindValue(":new_guide", new_item);
    query.exec();
}

void Dialog::on_close_Button_clicked()
{
    this->get_values();
    query= QSqlQuery(db);
    query.prepare("exec do_backup");
    query.exec();
//    query.exec("use master");
//    query.prepare("restore database workers from disk='C:\backup SQL\1.sql' with replace");
//    query.exec();
}
