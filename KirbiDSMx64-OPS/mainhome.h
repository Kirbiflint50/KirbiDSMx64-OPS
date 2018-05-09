#ifndef MAINHOME_H
#define MAINHOME_H

#include <QMainWindow>
#include <inttypes.h>
#include <stdio.h>
#include <ctime>
#include<windows.h>
#include<time.h>
#include "ui_mainhome.h"
#include <QDragEnterEvent>
namespace Ui {
class MainHome;
}

class MainHome : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainHome(QWidget *parent = 0);
    ~MainHome();

private slots:
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionPE_Infos_Memory_Map_View_triggered();

    void on_actionDump_1_Not_all_the_file_triggered();

    void on_actionDump_2_Not_all_the_file_triggered();

    void on_actionDump_3_Complete_triggered();

    void on_actionProtection_analyzer_triggered();

    void on_MainHome_windowTitleChanged(const QString &title);

    void on_MainHome_windowIconChanged(const QIcon &icon);

    void on_actionAddressConverter_values_converter_triggered();

    void on_actionImports_table_View_triggered();

    void on_actionExports_table_View_triggered();

    void on_actionRelocations_Viewer_triggered();

    void on_actionAll_Strings_triggered();

    void on_actionAddress_VA_triggered();

    void on_plainTextEdit_selectionChanged();

    void on_actionRVA_triggered();

    void on_actionOffset_triggered();

    void on_actionSelected_lines_triggered();

    void on_actionPattern_triggered();
    void keyPressEvent( QKeyEvent *event );



    void on_actionExpression_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionBinary_triggered();

    void on_actionSettings_triggered();

    void on_actionSection_adder_triggered();

    void on_actionImport_adder_triggered();

    void on_actionRelocation_adder_triggered();

    void on_actionDisassemble_a_section_triggered();

    void on_actionDump_1_Complete_triggered();

    void on_actionDump_2_Complete_triggered();

    void on_actionDump_3_Complete_2_triggered();

    void on_actionSave_disassembly_triggered();

    void on_actionSave_memory_map_triggered();

    void on_actionC_Decompiler_triggered();

    void on_actionC_code_triggered();

    void on_actionSave_imports_triggered();

    void dragEnterEvent(QDragEnterEvent *e);

    void dropEvent(QDropEvent *ev);

    void on_actionSave_exports_triggered();

    void on_actionSave_relocations_triggered();

    void on_actionRestart_triggered();

    void on_actionClear_triggered();

    void on_actionAbout_triggered();

public:
    Ui::MainHome *ui;


/*public slots:
    void gotoaddress(LONG64 addr, LONG64 endt, int engine);*/





};



#endif // MAINHOME_H
