#ifndef HEXDUMPSECOND_H
#define HEXDUMPSECOND_H

#include <QDialog>

namespace Ui {
class HexDumpSecond;
}

class HexDumpSecond : public QDialog
{
    Q_OBJECT

public:
    explicit HexDumpSecond(QWidget *parent = 0);
    ~HexDumpSecond();

private:
    Ui::HexDumpSecond *ui;

public:

    QString filelocation;

    QString filepath(QString loc) {

        filelocation = loc;
        return filelocation;
    }
private slots:
    void on_HexDumpSecond_windowTitleChanged(const QString &title);
    void on_plainTextEdit_textChanged();
};

#endif // HEXDUMPSECOND_H
