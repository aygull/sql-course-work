#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDebug>;
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

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_ok_Button_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{
    age = ui->age_spinBox->value();
    experinces = ui->experience_lineEdit->text();
    position = ui->position_lineEdit->text();
    Dialog* dialog = new Dialog(age, experinces, position);
    dialog->setModal(true);
    dialog->exec();
}
