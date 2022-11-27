#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->radioButton_1,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_checkBox_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
    QString str1 = "bn1";
    qDebug()<<str1;
}

void Dialog::on_checkBox_2_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setItalic(checked);
    ui->textEdit->setFont(font);
    QString str2 = "bn2";
    qDebug()<<str2;
}


void Dialog::on_checkBox_3_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setBold(checked);
    ui->textEdit->setFont(font);
    QString str3 = "bn3";
    qDebug()<<str3;

}

void Dialog::setTextFontColor()
{
    QPalette plet = ui->textEdit->palette();
    if(ui->radioButton_1->isChecked()){
        plet.setColor(QPalette::Text,Qt::black);
    }else if(ui->radioButton_2->isChecked()){
        plet.setColor(QPalette::Text,Qt::red);
    }else if(ui->radioButton_3->isChecked()){
       plet.setColor(QPalette::Text,Qt::blue);
    }
    ui->textEdit->setPalette(plet);
}









