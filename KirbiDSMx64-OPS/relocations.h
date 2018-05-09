#ifndef RELOCATIONS_H
#define RELOCATIONS_H

#include <QDialog>

namespace Ui {
class Relocations;
}

class Relocations : public QDialog
{
    Q_OBJECT

public:
    explicit Relocations(QWidget *parent = 0);
    ~Relocations();

private:
    Ui::Relocations *ui;

public:

    QString gtrlpth;

    QString reloc(QString pth) {

        gtrlpth = pth;
        return gtrlpth;
    }
private slots:
    void on_Relocations_windowTitleChanged(const QString &title);
};

#endif // RELOCATIONS_H
