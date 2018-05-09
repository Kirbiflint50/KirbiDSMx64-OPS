#ifndef DECOMPILER_H
#define DECOMPILER_H

#include <QDialog>

namespace Ui {
class Decompiler;
}

class Decompiler : public QDialog
{
    Q_OBJECT

public:
    explicit Decompiler(QWidget *parent = 0);
    ~Decompiler();

private slots:
    void on_Decompiler_windowTitleChanged(const QString &title);

private:
    Ui::Decompiler *ui;
};

#endif // DECOMPILER_H
