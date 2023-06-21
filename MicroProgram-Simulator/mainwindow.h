#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>
#include <vector>
#include <QTextBlock>
#include "instruction_f1.h"
#include "instruction_f2.h"
#include "instruction_f3.h"
#include "microprogram_instruction.h"
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
    bool isNumber(const QString& str);
    bool isCondition(const QString& str);
    bool isBranch(const QString& str);
    int command_f(QString command , int check);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    map<QString,int> table_variable;
    map<QString,int> condition;
    map<QString,int> branch;
    QStringList commands;
    int tcommmands;
    vector<F1> symbol_f1;
    vector<F2> symbol_f2;
    vector<F3> symbol_f3;
    vector<microprogram_i> ram_micro;
};
#endif // MAINWINDOW_H
