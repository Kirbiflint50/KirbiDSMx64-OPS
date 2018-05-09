#include "enteraddress.h"
#include "ui_enteraddress.h"

EnterAddress::EnterAddress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterAddress)
{
    ui->setupUi(this);
}

EnterAddress::~EnterAddress()
{
    delete ui;
}
