#ifndef STRINGS_H
#define STRINGS_H

#include <QDialog>

namespace Ui {
class Strings;
}

class Strings : public QDialog
{
    Q_OBJECT

public:
    explicit Strings(QWidget *parent = 0);
    ~Strings();

private:
    Ui::Strings *ui;

public:

    QString strtr;

    QString location(QString path) {

        strtr = path;
        return strtr;
    }
private slots:
    void on_Strings_windowTitleChanged(const QString &title);
};

#endif // STRINGS_H
