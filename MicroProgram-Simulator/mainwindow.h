#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <map>
#include <vector>
#include <QTextBlock>
#include <QFileDialog>
#include <fstream>
#include <sstream>
#include <QFile>
#include <bitset>
#include "instruction_f1.h"
#include "instruction_f2.h"
#include "instruction_f3.h"
#include "microprogram_instruction.h"
#include "assembly_instruction.h"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printTable_RAM();
    void printTable_Microgram();
    void printrow_ram(int lc);
    QString dectohex(int n);
    bool isNumber(const QString& str);
    bool isCondition(const QString& str);
    bool isBranch(const QString& str);
    int command_f(QString command , int check);
protected:
    void compile_assembly();

private slots:
    void on_pushButton_clicked();

    void on_open_micro_clicked();

    void on_save_micro_clicked();

    void on_actionsave_as_microprogram_triggered();

    void on_new_micro_clicked();

    void on_save_assembly_clicked();

    void on_actionsave_microprogram_triggered();

    void on_actionopen_microprogram_triggered();

    void on_actionsave_as_assembly_code_triggered();

    void on_actionsave_assembly_code_triggered();

    void on_actionopen_assembly_code_triggered();

    void on_actionnew_assembly_code_triggered();

    void on_actionnew_microprogram_triggered();

    void on_actionexit_triggered();

    void on_actioncompile_triggered();

    void on_open_assembly_clicked();

    void on_new_assembly_clicked();

    void on_actionabout_project_triggered();

private:
    Ui::MainWindow *ui;
    QString issaved_micro="";
    QString issaved_assembly="";
    map<QString,int> table_variable;
    map<QString,int> table_variable_assembly;
    map<QString,int> condition;
    map<QString,int> branch;
    //QStringList commands;
    int tcommmands;
    vector<F1> symbol_f1;
    vector<F2> symbol_f2;
    vector<F3> symbol_f3;
    vector<microprogram_i*> ram_micro ;
    vector<assembly_i> ram_assembly;
};
#endif // MAINWINDOW_H
