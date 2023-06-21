#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    F1 ins;
    ins.set_intersection("NOP");
    ins.set_dec("NO OPERATION");
    symbol_f1.push_back(ins);
    ins.set_intersection("ADD");
    ins.set_dec("AC");
    symbol_f1.push_back(ins);
    ins.set_intersection("CLRAC");
    ins.set_dec("AC");
    symbol_f1.push_back(ins);
    ins.set_intersection("INCAC");
    ins.set_dec("AC");
    symbol_f1.push_back(ins);
    ins.set_intersection("DRTAC");
    ins.set_dec("AC");
    symbol_f1.push_back(ins);
    ins.set_intersection("DRTAR");
    ins.set_dec("AR");
    symbol_f1.push_back(ins);
    ins.set_intersection("PCTAR");
    ins.set_dec("AR");
    symbol_f1.push_back(ins);
    ins.set_intersection("WRITE");
    ins.set_dec("M[AR]");
    symbol_f1.push_back(ins);
    F2 ins2;
    ins2.set_intersection("NOP");
    ins2.set_dec("NO OPERATION");
    symbol_f2.push_back(ins2);
    ins2.set_intersection("SUB");
    ins2.set_dec("AC");
    symbol_f2.push_back(ins2);
    ins2.set_intersection("OR");
    ins2.set_dec("AC");
    symbol_f2.push_back(ins2);
    ins2.set_intersection("AND");
    ins2.set_dec("AC");
    symbol_f2.push_back(ins2);
    ins2.set_intersection("READ");
    ins2.set_dec("DR");
    symbol_f2.push_back(ins2);
    ins2.set_intersection("ACTDR");
    ins2.set_dec("DR");
    symbol_f2.push_back(ins2);
    ins2.set_intersection("INCDR");
    ins2.set_dec("DR");
    symbol_f2.push_back(ins2);
    ins2.set_intersection("PCTDR");
    ins2.set_dec("DR");
    symbol_f2.push_back(ins2);
    F3 ins3;
    ins3.set_intersection("NOP");
    ins3.set_dec("NO OPERATION");
    symbol_f3.push_back(ins3);
    ins3.set_intersection("XOR");
    ins3.set_dec("AC");
    symbol_f3.push_back(ins3);
    ins3.set_intersection("COM");
    ins3.set_dec("AC");
    symbol_f3.push_back(ins3);
    ins3.set_intersection("SHL");
    ins3.set_dec("AC");
    symbol_f3.push_back(ins3);
    ins3.set_intersection("SHR");
    ins3.set_dec("AC");
    symbol_f3.push_back(ins3);
    ins3.set_intersection("INCPC");
    ins3.set_dec("PC");
    symbol_f3.push_back(ins3);
    ins3.set_intersection("ARTPC");
    ins3.set_dec("PC");
    symbol_f3.push_back(ins3);
    condition["U"] = 0;
    condition["I"] = 1;
    condition["S"] = 2;
    condition["Z"] = 3;
    condition["u"] = 0;
    condition["i"] = 1;
    condition["s"] = 2;
    condition["z"] = 3;
    branch["JMP"] = 0;
    branch["CALL"] = 1;
    branch["RET"] = 2;
    branch["MAP"] = 3;
    ram_micro.resize(128);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isNumber(const QString &str)
{
    string check=str.toStdString();
    for (char const &c : check)
    {
        if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f'|| c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F'|| c=='-' || c=='+')
        {
            continue;
        }
        if (isdigit(c) == 0) return false;
    }
       return true;
}
void MainWindow::on_pushButton_clicked()
{
    tcommmands = ui->Microprogram->document()->blockCount();
    QTextDocument *doc = ui->Microprogram->document();
    ui->console->setText("");
    int lc1=0;
    QStringList riz_command;
    QTextBlock tb;
    for(int i=1;i<=tcommmands;i++)
    {
    tb = doc->findBlockByLineNumber(i);
    riz_command = tb.text().split(' ', Qt::SkipEmptyParts);
    if(riz_command.size()==0)
        continue;
    else
    {
        if(riz_command.at(0)[riz_command.at(0).size()-1]==':')
        {
            QString wait="";
            for(int cw=0;cw<riz_command.at(0).size()-1;cw++)
            {
                wait+=riz_command.at(0)[cw];
            }
            table_variable[wait]=lc1;
            lc1++;
        }
        else
        {
            if(riz_command.at(0)=="ORG")
            {
                if(isNumber(riz_command.at(1)))
                {
                    bool ok=1;
                    lc1=riz_command.at(1).toInt(&ok,16);
                    continue;

                }
                else
                {
                    ui->console->setText("error in line:"+QString::number(i)+"\n You need hex number after ORG. \n");
                    break;
                }
            }
            else
            {
                lc1++;
            }
        }
    }

    }
    lc1=0;
    QStringList riz_f;
    for(int i=1;i<=tcommmands;i++)
    {
        tb = doc->findBlockByLineNumber(i);
        riz_command = tb.text().split('/', Qt::SkipEmptyParts);
        if(riz_command.size()==0)
            continue;
        else
        {
            riz_f = riz_command.at(0).split(',' , Qt::SkipEmptyParts);
            switch( riz_f.size())
            {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;
            }
            if(riz_command.at(0)[riz_command.at(0).size()-1]==':')
            {
                QString wait="";
                for(int cw=0;cw<riz_command.at(0).size()-1;cw++)
                {
                    wait+=riz_command.at(0)[cw];
                }
                //line = table_variable[wait];
                lc1++;
            }
            else
            {
                if(riz_command.at(0)=="ORG")
                {
                    if(isNumber(riz_command.at(1)))
                    {
                        bool ok=1;
                        lc1=riz_command.at(1).toInt(&ok,16);
                        continue;

                    }
                    else
                    {
                        ui->console->setText("error in line:"+QString::number(i)+"\n You need hex number after ORG. \n");
                        break;
                    }
                }
                else
                {
                    lc1++;
                }
            }
        }
    }
}

