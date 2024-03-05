#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"

Registerwindow::Registerwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Registerwindow)
{
    ui->setupUi(this);
    ui->doberror->setVisible(false);
    ui->passworderror->setVisible(false);
    ui->usernameerror->setVisible(false);
    ui->registrationerror->setVisible(false);
}

Registerwindow::~Registerwindow()
{
    delete ui;
}

void Registerwindow::on_pushButton_clicked()
{ui->usernameerror->setVisible(false);
    ui->passworderror->setVisible(false);
    ui->doberror->setVisible(false);
    ui->registrationerror->setVisible(false);


    QString un=ui->username->text();
    for(int i=0;i<100;i++){
        if(un==usernames[i])
        {
            ui->usernameerror->setVisible(true);
        }
    }
    QString pass=ui->password->text();
    QString pass2=ui->password2->text();
    if(pass!=pass2)
    {
        ui->passworderror->setVisible(true);
    }
    QString m=ui->comboBox->currentText();
    QString d=ui->day->text();
    QString str=ui->year->text();
    int y=str.toInt();
    if(2024-y<12)
    {
        ui->doberror->setVisible(true);
    }
    QString gen;
    if(ui->female->isChecked())
    {
        gen="Female";
    }
    else if(ui->male->isChecked())
    {
        gen="Male";
    }
    else if(!ui->male->isChecked() && ui->female->isChecked())
    {
        ui->registrationerror->setVisible(true);
    }
    QString type;
    if(ui->admin->isChecked())
    {
        type="admin";
    }
    else if(ui->user->isChecked())
    {
        type="user";
    }
    else if(!ui->user->isChecked()&&!ui->admin->isChecked())
    {
        ui->registrationerror->setVisible(true);
    }
    if(!ui->checkBox->isChecked()&&!ui->checkBox_2->isChecked()&&!ui->checkBox_3->isChecked()&& !ui->checkBox_4->isChecked()&& !ui->checkBox_5->isChecked() && !ui->checkBox_6->isChecked())
    {
        ui->registrationerror->setVisible(true);
    }
    if(!ui->registrationerror->isVisible() && !ui->passworderror->isVisible() && !ui->usernameerror->isVisible() && !ui->doberror->isVisible())
    {
        usernames[usersCount]=un;
        passwords[usersCount]=pass;
        ages[usersCount]=2024-y;
        int age= 2024-y;
        usersCount++;
        hide();
        Welcomewindow* welcomewindow=new Welcomewindow(un,age,this);
        welcomewindow->show();
    }
}

