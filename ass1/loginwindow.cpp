#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include "registerwindow.h"

Loginwindow::Loginwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Loginwindow)
{
    ui->setupUi(this);
    ui->error->setVisible(false);
}

Loginwindow::~Loginwindow()
{
    delete ui;
}

void Loginwindow::on_login_clicked()
{
    QString un=ui->username->text();
    QString p=ui->password->text();
    for(int i=0;i<100;i++)
    {
        if(un==usernames[i])
        {
            if(p==passwords[i])
            {
                hide();
                Welcomewindow* welcomewindow=new Welcomewindow(un, ages[i],this);
                welcomewindow->show();
            }
        }
        else {
            ui->error->setVisible(true);
        }

        }
}


void Loginwindow::on_register_2_clicked()
{
    hide();
    Registerwindow* registerwindow=new Registerwindow (this);
    registerwindow->show();
}

