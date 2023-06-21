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

bool isCondition(const QString& str)
{
    string check=str.toStdString();
    if(check =="U" || check=="u" || check=="I" || check=="i" || check=="s" || check=="S"|| check=="z" || check=="Z" )
    {
            return true;
    }
    else return false;
}

bool isBranch(const QString& str)
{
    string check=str.toStdString();
    if(check =="JMP" || check=="CALL" || check=="RET" || check=="MAP" )
    {
            return true;
    }
    else return false;
}

int command_f(QString command , int check)
{
    if(check == 0)
    {
        if(command == "NOP")
            return 0;
        else
            if(command == "ADD")
                return 4;
            else
                if(command == "CLRAC")
                    return 8;
                else
                    if(command == "INCAC")
                        return 12;
                    else
                        if(command == "DRTAC")
                            return 16;
                        else
                            if(command == "DRTAR")
                                return 20;
                            else
                                if(command == "PCTAR")
                                    return 24;
                                else
                                    if(command == "WRITE")
                                        return 28;
    }
    if(check == 0 || check == 1)
    {
        if(command == "NOP")
            return 1;
        else
            if(command == "SUB")
                return 5;
            else
                if(command == "OR")
                    return 9;
                else
                    if(command == "AND")
                        return 13;
                    else
                        if(command == "READ")
                            return 17;
                        else
                            if(command == "ACTDR")
                                return 21;
                            else
                                if(command == "INCDR")
                                    return 25;
                                else
                                    if(command == "PCTDR")
                                        return 29;
    }
    if(check == 0 || check == 1 || check == 2)
    {
        if(command == "NOP")
            return 2;
        else
            if(command == "XOR")
                return 6;
            else
                if(command == "COM")
                    return 10;
                else
                    if(command == "SHL")
                        return 14;
                    else
                        if(command == "SHR")
                            return 18;
                        else
                            if(command == "INCPC")
                                return 22;
                            else
                                if(command == "ARTPC")
                                    return 26;
                                else
                                    return 3;
                            }

}

void MainWindow::on_pushButton_clicked()
{
    tcommmands = ui->Microprogram->document()->blockCount();
    QTextDocument *doc = ui->Microprogram->document();
    ui->console->setText("");
    int  error = 0 , lc1=0 , org=0;
    QStringList riz_command;
    QTextBlock tb;
    for(int i=1;i<=tcommmands;i++)
    {
    error = 0;
    tb = doc->findBlockByLineNumber(i);
    riz_command = tb.text().split(' ', Qt::SkipEmptyParts);
    if(riz_command.size()==0)
        continue;
    else
    {
        if(riz_command.at(0)[riz_command.at(0).size()-1]==':')
        {
            if(org == 0)
            {
                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n You must write ORG first. \n");
                error = 1;
                break;
            }
            QString wait="";
            for(int cw=0;cw<riz_command.at(0).size()-1;cw++)
            {
                wait+=riz_command.at(0)[cw];
            }
            if(wait == "NEXT")
            {
                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n The label cannot be the word NEXT. \n");
                error = 1;
                break;
            }
            else
            {
                table_variable[wait]=lc1;
                lc1++;
            }
        }
        else
        {
            if(riz_command.at(0)=="ORG")
            {
                org=1;
                if(isNumber(riz_command.at(1)))
                {
                    bool ok=1;
                    lc1=riz_command.at(1).toInt(&ok,16);
                    continue;
                }
                else
                {
                    ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n You need hex number after ORG. \n");
                    error = 1;
                    break;
                }
            }
            else
            {
                if(tb.text()[0] != '/')
                {
                    lc1++;
                }
            }
        }
    }

    }
    lc1=0;
    QStringList riz_f;
    QStringList check1 , check2;
    QStringList riz_f_command;
    microprogram_i instruction;
    int com_f , control_f=0;
if(error !=1)
{
    for(int i=1;i<=tcommmands;i++)
    {
        control_f = 0;
        error = 0;
        com_f = 0;
        tb = doc->findBlockByLineNumber(i);
        check1 = tb.text().split(' ', Qt::SkipEmptyParts);
        if(check1.size()==0)
            continue;
        if(check1.at(0)=="ORG")
        {
            bool ok=1;
            lc1=check1.at(1).toInt(&ok,16);
            continue;
        }
        else
            lc1++;
        if(tb.text()[0] != '/')
        {
            riz_command = tb.text().split('/', Qt::SkipEmptyParts);
            check2 = riz_command.at(0).split(':', Qt::SkipEmptyParts);
            if(check2.size() == 1)
                riz_f = riz_command.at(0).split(',' , Qt::SkipEmptyParts);
            else
                riz_f = riz_command.at(1).split(',' , Qt::SkipEmptyParts);
            switch( riz_f.size())
            {
            case 1:
                riz_f_command=riz_f.at(0).split(' ' , Qt::SkipEmptyParts);
                if(isCondition(riz_f_command.at(1)))
                {
                    if(isBranch(riz_f_command.at(2)))
                    {
                        if(riz_f_command.at(2) == "MAP")
                        {
                            if(riz_f_command.size() > 3)
                            {
                                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n No address is needed for the MAP command. \n");
                                error = 1;
                                break;
                            }
                            else
                            {
                                com_f = command_f(riz_f_command.at(0) , 0);
                                if(com_f % 4 == 0)
                                {
                                    instruction.set_f1(symbol_f1.at((com_f/4)));
                                    instruction.set_f2(symbol_f2.at(0));
                                    instruction.set_f3(symbol_f3.at(0));
                                }
                                else
                                {
                                    if(com_f % 4 == 1)
                                    {
                                        instruction.set_f1(symbol_f1.at(0));
                                        instruction.set_f2(symbol_f2.at((com_f/4)));
                                        instruction.set_f3(symbol_f3.at(0));
                                    }
                                    else
                                        if(com_f % 4 == 2)
                                        {
                                            instruction.set_f1(symbol_f1.at(0));
                                            instruction.set_f2(symbol_f2.at(0));
                                            instruction.set_f3(symbol_f3.at((com_f/4)));
                                        }
                                        else
                                        {
                                            ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n F1, F2, F3 entered incorrectly. \n");
                                            error = 1;
                                            break;
                                        }
                                }
                                instruction.set_f3(symbol_f3.at(0));
                                instruction.set_branch(branch[riz_f_command.at(2)]);
                                instruction.set_condition(condition[riz_f_command.at(1)]);
                                instruction.set_write(true);
                            }
                        }
                        else
                        {
                            if(riz_f_command.size() > 4)
                            {
                                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n The syntax is incorrect. \n");
                                error = 1;
                                break;
                            }
                            else
                            {
                                if(table_variable.find(riz_f_command.at(3))!=condition.end() || riz_f_command.at(3) == "NEXT")
                                {
                                    com_f = command_f(riz_f_command.at(0) , 0);
                                    if(com_f % 4 == 0)
                                    {
                                    instruction.set_f1(symbol_f1.at((com_f/4)));
                                    instruction.set_f2(symbol_f2.at(0));
                                    instruction.set_f3(symbol_f3.at(0));
                                    }
                                    else
                                    {
                                        if(com_f % 4 == 1)
                                        {
                                            instruction.set_f1(symbol_f1.at(0));
                                            instruction.set_f2(symbol_f2.at((com_f/4)));
                                            instruction.set_f3(symbol_f3.at(0));
                                        }
                                        else
                                            if(com_f % 4 == 2)
                                            {
                                                instruction.set_f1(symbol_f1.at(0));
                                                instruction.set_f2(symbol_f2.at(0));
                                                instruction.set_f3(symbol_f3.at((com_f/4)));
                                            }
                                            else
                                            {
                                                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n F1, F2, F3 entered incorrectly. \n");
                                                error = 1;
                                                break;
                                            }
                                        instruction.set_branch(branch[riz_f_command.at(2)]);
                                        instruction.set_condition(condition[riz_f_command.at(1)]);
                                        instruction.set_write(true);
                                        if(riz_f_command.at(3) != "NEXT")
                                        {
                                            instruction.set_address(table_variable[riz_f_command.at(3)]);
                                        }
                                        else
                                        {
                                            instruction.set_address(lc1+1);
                                        }
                                    }
                                }
                                else
                                {
                                    ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n There is no such label. \n");
                                    error = 1;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n There is no such branch. \n");
                        error = 1;
                        break;
                    }
                }
                else
                {
                    ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n There is no such condition. \n");
                    error = 1;
                    break;
                }
                break;
            case 2:
                com_f = command_f(riz_f.at(0) , 0);
                if(com_f % 4 == 0)
                {
                    instruction.set_f1(symbol_f1.at((com_f/4)));
                    control_f = 1;
                }
                else
                {
                    if(com_f % 4 == 1)
                    {
                        instruction.set_f1(symbol_f1.at(0));
                        instruction.set_f2(symbol_f2.at((com_f/4)));
                        control_f = 2;
                    }
                    else
                    {
                        ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n F1, F2, F3 entered incorrectly. \n");
                        error = 1;
                        break;
                    }
                }
                riz_f_command=riz_f.at(1).split(' ' , Qt::SkipEmptyParts);
                if(isCondition(riz_f_command.at(1)))
                {
                    if(isBranch(riz_f_command.at(2)))
                    {
                        if(riz_f_command.at(2) == "MAP")
                        {
                            if(riz_f_command.size() > 3)
                            {
                                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n No address is needed for the MAP command. \n");
                                error = 1;
                                break;
                            }
                            else
                            {
                                com_f = command_f(riz_f_command.at(0) , control_f);
                                if(com_f % 4 == 1 && control_f == 1)
                                {
                                    instruction.set_f2(symbol_f2.at((com_f/4)));
                                    instruction.set_f3(symbol_f3.at(0));
                                }
                                else
                                    if(com_f % 4 == 2 && control_f == 1)
                                    {
                                        instruction.set_f2(symbol_f2.at(0));
                                        instruction.set_f3(symbol_f3.at((com_f/4)));
                                    }
                                    else
                                    {
                                        if((com_f % 4 == 2 && control_f == 2))
                                        {
                                            instruction.set_f3(symbol_f3.at((com_f/4)));
                                        }
                                        else
                                        {
                                            ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n F1, F2, F3 entered incorrectly. \n");
                                            error = 1;
                                            break;
                                        }
                                    }
                                instruction.set_f3(symbol_f3.at(0));
                                instruction.set_branch(branch[riz_f_command.at(2)]);
                                instruction.set_condition(condition[riz_f_command.at(1)]);
                                instruction.set_write(true);
                            }
                        }
                        else
                        {
                            if(riz_f_command.size() > 4)
                            {
                                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n The syntax is incorrect. \n");
                                error = 1;
                                break;
                            }
                            else
                            {
                                if(table_variable.find(riz_f_command.at(3))!=condition.end() || riz_f_command.at(3) == "NEXT")
                                {
                                    com_f = command_f(riz_f_command.at(0) , control_f);
                                    if(com_f % 4 == 1 && control_f == 1)
                                    {
                                        instruction.set_f2(symbol_f2.at((com_f/4)));
                                        instruction.set_f3(symbol_f3.at(0));
                                    }
                                    else
                                    {
                                        if(com_f % 4 == 2 && control_f == 1)
                                        {
                                            instruction.set_f2(symbol_f2.at(0));
                                            instruction.set_f3(symbol_f3.at((com_f/4)));
                                        }
                                        else
                                        {
                                            if((com_f % 4 == 2 && control_f == 2))
                                            {
                                                instruction.set_f3(symbol_f3.at((com_f/4)));
                                            }
                                            else
                                            {
                                                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n F1, F2, F3 entered incorrectly. \n");
                                                error = 1;
                                                break;
                                            }
                                        }
                                    }
                                    instruction.set_branch(branch[riz_f_command.at(2)]);
                                    instruction.set_condition(condition[riz_f_command.at(1)]);
                                    instruction.set_write(true);
                                    if(riz_f_command.at(3) != "NEXT")
                                    {
                                        instruction.set_address(table_variable[riz_f_command.at(3)]);
                                    }
                                    else
                                    {
                                        instruction.set_address(lc1+1);
                                    }
                                }

                                else
                                {
                                    ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n There is no such label. \n");
                                    error = 1;
                                    break;
                                }
                            }
                            }
                    }
                    else
                    {
                        ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n There is no such branch. \n");
                        error = 1;
                        break;
                    }
                }
                else
                {
                    ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n There is no such condition. \n");
                    error = 1;
                    break;
                }
                break;
            case 3:
                com_f = command_f(riz_f.at(0) , 0);
                if(com_f % 4 == 0)
                {
                    instruction.set_f1(symbol_f1.at((com_f/4)));
                    com_f = command_f(riz_f.at(1) , 1);
                    if(com_f % 4 == 1)
                    {
                        instruction.set_f2(symbol_f2.at((com_f/4)));
                        riz_f_command=riz_f.at(2).split(' ' , Qt::SkipEmptyParts);
                        com_f = command_f(riz_f_command.at(0) , 1);
                        if(com_f % 4 == 2)
                        {
                            instruction.set_f3(symbol_f3.at((com_f/4)));
                            if(isCondition(riz_f_command.at(1)))
                            {
                                if(isBranch(riz_f_command.at(2)))
                                {
                                    if(riz_f_command.at(2) == "MAP")
                                    {
                                        if(riz_f_command.size() > 3)
                                        {
                                            ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n No address is needed for the MAP command. \n");
                                            error = 1;
                                            break;
                                        }
                                        else
                                        {
                                            instruction.set_f3(symbol_f3.at(0));
                                            instruction.set_branch(branch[riz_f_command.at(2)]);
                                            instruction.set_condition(condition[riz_f_command.at(1)]);
                                            instruction.set_write(true);
                                        }
                                    }
                                    else
                                    {
                                        if(riz_f_command.size() > 4)
                                        {
                                            ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n The syntax is incorrect. \n");
                                            error = 1;
                                            break;
                                        }
                                        else
                                        {
                                            if(table_variable.find(riz_f_command.at(3))!=condition.end() || riz_f_command.at(3) == "NEXT")
                                            {
                                                instruction.set_branch(branch[riz_f_command.at(2)]);
                                                instruction.set_condition(condition[riz_f_command.at(1)]);
                                                instruction.set_write(true);
                                                if(riz_f_command.at(3) != "NEXT")
                                                {
                                                    instruction.set_address(table_variable[riz_f_command.at(3)]);
                                                }
                                                else
                                                {
                                                    instruction.set_address(lc1+1);
                                                }
                                            }

                                            else
                                            {
                                                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n There is no such label. \n");
                                                error = 1;
                                                break;
                                            }
                                        }
                                        }
                                }
                                else
                                {
                                    ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n There is no such branch. \n");
                                    error = 1;
                                    break;
                                }
                            }
                            else
                            {
                                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n There is no such condition. \n");
                                error = 1;
                                break;
                            }

                        }
                        else
                        {
                            ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n F1, F2, F3 entered incorrectly. \n");
                            error = 1;
                            break;
                        }
                    }
                    else
                    {
                        ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n F1, F2, F3 entered incorrectly. \n");
                        error = 1;
                        break;
                    }
                }
                else
                {
                    ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n F1, F2, F3 entered incorrectly. \n");
                    error = 1;
                    break;
                }

                break;
            default:
                ui->console->setText("Microprogram : error in line:"+QString::number(i)+"\n F1, F2, F3 entered incorrectly. \n");
                error = 1;
                break;
            }
            if(error)
                break;
        }
    }
}
if(error != 1)
{
    ui->console->setText("Microprogram was compiled successfully \n");
}

}
