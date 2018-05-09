#ifndef SECTIONSADDER_H
#define SECTIONSADDER_H

#include <QDialog>

namespace Ui {
class SectionsAdder;
}

class SectionsAdder : public QDialog
{
    Q_OBJECT

public:
    explicit SectionsAdder(QWidget *parent = 0);
    ~SectionsAdder();

private slots:
    void on_SectionsAdder_windowTitleChanged(const QString &title);

    void on_pushButton_clicked();

private:
    Ui::SectionsAdder *ui;

public:

    QString target;

    QString getterg(QString path) {

        target = path;
        return target;
    }
};

#endif // SECTIONSADDER_H
