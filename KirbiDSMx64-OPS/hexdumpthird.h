#ifndef HEXDUMPTHIRD_H
#define HEXDUMPTHIRD_H

#include <QDialog>

namespace Ui {
class HexDumpThird;
}

class HexDumpThird : public QDialog
{
    Q_OBJECT

public:
    explicit HexDumpThird(QWidget *parent = 0);
    ~HexDumpThird();

private:
    Ui::HexDumpThird *ui;

public:
    QString pathret;

    QString getpath(QString name) {

        pathret = name;
        return pathret;

    }
private slots:
    void on_HexDumpThird_windowTitleChanged(const QString &title);
};

#endif // HEXDUMPTHIRD_H
