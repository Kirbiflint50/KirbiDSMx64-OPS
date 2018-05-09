#ifndef HEXDUMP1_H
#define HEXDUMP1_H

#include <QDialog>


namespace Ui {
class HexDump1;
}

class HexDump1 : public QDialog
{
    Q_OBJECT

public:
    explicit HexDump1(QWidget *parent = 0);
    ~HexDump1();

private:
    Ui::HexDump1 *ui;

public:
    QString file;
    QString gethex(QString filepath) {

        file = filepath;
        return file;

            }
private slots:
    void on_HexDump1_windowTitleChanged(const QString &title);
};

#endif // HEXDUMP1_H
