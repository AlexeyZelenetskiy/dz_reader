#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
     if(ui->lineEdit->text() == "")
     {
         QMessageBox::information(this, "Erore!" , "you do not specify the path");
         return;
     }
     else
     {
         emit pathSelected(ui->lineEdit->text());
         close();
     }
}

void Dialog::on_pushButton_2_clicked()
{
    close();
}
