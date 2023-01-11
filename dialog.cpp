#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <gdal_priv.h>

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

void Dialog::on_pushButton_4_clicked()
{
//    ui->textEdit->clear();
    QList<QString> list;
    list<<"FWH"<<"FWX"<<"CDY";
    QListIterator<QString> i (list);
    while (i.hasNext()) {
        ui->textEdit->appendPlainText(i.next());

    }
    const char* pszFile;
        GDALAllRegister();
        pszFile = "D:/1.tif";
        GDALDataset* poDataset = (GDALDataset*)GDALOpen(pszFile, GA_ReadOnly);
        GDALRasterBand* poBand = poDataset->GetRasterBand(1);
        QString Description = poDataset->GetDescription();
        QString DriverName = poDataset->GetDriverName();
        int LayerCount = poDataset->GetRasterXSize();
        int band = poBand->GetBand();
        int xsize = poBand->GetXSize();
        int ysize = poBand->GetYSize();
        ui->textEdit->appendPlainText(Description);
        ui->textEdit->appendPlainText(DriverName);

}

void Dialog::on_dial_valueChanged(int value)
{
    Q_UNUSED(value);
    int value_dial = ui->dial->value();
    QString str = str.asprintf("%d",value_dial);
    ui->lcdNumber->display(str);
}
