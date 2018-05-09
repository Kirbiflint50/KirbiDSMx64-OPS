#ifndef IMPORTSTABLE_H
#define IMPORTSTABLE_H

#include <QDialog>

namespace Ui {
class ImportsTable;
}

class ImportsTable : public QDialog
{
    Q_OBJECT

public:
    explicit ImportsTable(QWidget *parent = 0);
    ~ImportsTable();

private:
    Ui::ImportsTable *ui;

public:

    QString fileimp;

    QString gthloc(QString fl) {

        fileimp = fl;
        return fileimp;
    }
private slots:
    void on_ImportsTable_windowTitleChanged(const QString &title);
    void on_ImportsTable_windowIconChanged(const QIcon &icon);
    void on_ImportsTable_accepted();
};

#endif // IMPORTSTABLE_H
