#ifndef PROTECTIONANALYZER_H
#define PROTECTIONANALYZER_H

#include <QDialog>

namespace Ui {
class ProtectionAnalyzer;
}

class ProtectionAnalyzer : public QDialog
{
    Q_OBJECT

public:
    explicit ProtectionAnalyzer(QWidget *parent = 0);
    ~ProtectionAnalyzer();

private:
    Ui::ProtectionAnalyzer *ui;


   public:

    QString sections;

    QString getSections(QString data){

        sections = data;
        return sections;
    }
private slots:
    void on_ProtectionAnalyzer_windowTitleChanged(const QString &title);
    void on_pushButton_clicked();
};

#endif // PROTECTIONANALYZER_H
