#ifndef EXPORTTABLE_H
#define EXPORTTABLE_H

#include <QDialog>

namespace Ui {
class ExportTable;
}

class ExportTable : public QDialog
{
    Q_OBJECT

public:
    explicit ExportTable(QWidget *parent = 0);
    ~ExportTable();

private slots:
    void on_ExportTable_windowTitleChanged(const QString &title);

private:
    Ui::ExportTable *ui;

public:

    QString fileex;

    QString getex(QString path) {

        fileex = path;
        return fileex;
    }
};

#endif // EXPORTTABLE_H
