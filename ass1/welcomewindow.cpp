#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include"loginwindow.h"

Welcomewindow::Welcomewindow( QString username, int age,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Welcomewindow)
{
    ui->setupUi(this);
    QString str=QString :: number(age);
    ui->hello->setText("Hello "+ username +" "+ str);
    QPixmap pix (":/Users/janarowan/Desktop/labassignment1/assignment_1/image.jpg");
    int w=ui->image->width();
    int h=ui->image->height();
    ui->image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Welcomewindow::~Welcomewindow()
{
    delete ui;
}

void Welcomewindow::on_logout_clicked()
{
    hide();
    Loginwindow* loginwindow=new Loginwindow(this);
    loginwindow->show();
}

