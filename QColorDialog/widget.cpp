#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QFontDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_textColor_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color(QPalette::WindowText);
    QColor selectedColor = QColorDialog::getColor(color, this, "Choose Text Color");
    if(selectedColor.isValid())
    {
        palette.setColor(QPalette::WindowText, selectedColor);
        ui->label->setPalette(palette);
        qDebug() << "User Choosen a valid color";
    }
    else
    {
        qDebug() << "User choosen an invalid color";
    }

}

void Widget::on_pushButton_backgroundColor_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color(QPalette::Background);
    QColor selectedColor = QColorDialog::getColor(color, this, "Choose Background Color");
    if(selectedColor.isValid())
    {
        palette.setColor(QPalette::Background, selectedColor);
        ui->label->setPalette(palette);
        qDebug() << "User Choosen a valid color";
    }
    else
    {
        qDebug() << "User choosen an invalid color";
    }
}

void Widget::on_pushButton_font_clicked()
{
    bool ok;
    QFont selectedFont = QFontDialog::getFont(&ok, ui->label->font(), this, "Choose Font");
    if(ok)
    {
        ui->label->setFont(selectedFont);
        qDebug() << "User Choosen a valid Font";
    }
    else
    {
        qDebug() << "User Choosen an invalid Font";
    }


}
