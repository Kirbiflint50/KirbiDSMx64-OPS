#ifndef ENTERADDRESS_H
#define ENTERADDRESS_H

#include <QDialog>

namespace Ui {
class EnterAddress;
}

class EnterAddress : public QDialog
{
    Q_OBJECT

public:
    explicit EnterAddress(QWidget *parent = 0);
    ~EnterAddress();

private:
    Ui::EnterAddress *ui;
};

#endif // ENTERADDRESS_H
