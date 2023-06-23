#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("MicroProgram Simulator");
    F1 ins;
    ins.set_intersection("NOP");
    ins.set_dec("NO OPERATION1");
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
    ins2.set_dec("NO OPERATION2");
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
    ins3.set_dec("NO OPERATION3");
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
    ram_assembly.resize(2048);
    setWindowIcon(QIcon(":/new/prefix1/pic/icon.png"));
    ui->save_assembly->setIcon(QIcon(":/new/prefix1/pic/save.png"));
    ui->open_assembly->setIcon(QIcon(":/new/prefix1/pic/open.png"));
    ui->new_assembly->setIcon(QIcon(":/new/prefix1/pic/new.png"));
    ui->save_micro->setIcon(QIcon(":/new/prefix1/pic/save.png"));
    ui->open_micro->setIcon(QIcon(":/new/prefix1/pic/open.png"));
    ui->new_micro->setIcon(QIcon(":/new/prefix1/pic/new.png"));
    ui->next_step->setIcon(QIcon(":/new/prefix1/pic/stepnext.png"));
    ui->continue_2->setIcon(QIcon(":/new/prefix1/pic/continue.png"));
    ui->stop->setIcon(QIcon(":/new/prefix1/pic/stop.png"));
    ui->restart->setIcon(QIcon(":/new/prefix1/pic/restart.png"));
    ui->save_assembly->setIconSize(QSize(35, 35));
    ui->open_assembly->setIconSize(QSize(35, 35));
    ui->new_assembly->setIconSize(QSize(35, 35));
    ui->save_micro->setIconSize(QSize(35, 35));
    ui->open_micro->setIconSize(QSize(35, 35));
    ui->new_micro->setIconSize(QSize(35, 35));
    ui->next_step->setIconSize(QSize(35, 35));
    ui->continue_2->setIconSize(QSize(35,35));
    ui->restart->setIconSize(QSize(35,35));
    ui->stop->setIconSize(QSize(35,35));
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

bool MainWindow::isCondition(const QString& str)
{
    string check=str.toStdString();
    if(check =="U" || check=="u" || check=="I" || check=="i" || check=="s" || check=="S"|| check=="z" || check=="Z" )
    {
            return true;
    }
    else return false;
}

bool MainWindow::isBranch(const QString& str)
{
    string check=str.toStdString();
    if(check =="JMP" || check=="CALL" || check=="RET" || check=="MAP" )
    {
            return true;
    }
    else return false;
}

int MainWindow::command_f(QString command , int check)
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
    return 3;
}

void MainWindow::on_pushButton_clicked()
{
    tcommmands = ui->Microprogram->document()->blockCount();
    QTextDocument *doc = ui->Microprogram->document();
    ui->console->setText("");
    int  error = 0 , lc1=0 , org=0;
    QStringList riz_command;
    QTextBlock tb;
    for(int i=0;i<tcommmands;i++)
    {
    if(lc1>128)
    {
        ui->console->setText("ERROR: OVERFLOW MICROPROGRAM RAM!\n");
        error=1;
        break;
    }
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
                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n You must write ORG first. \n");
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
                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n The label cannot be the word NEXT. \n");
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
                    ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n You need hex number after ORG. \n");
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
    if(org !=1)
    {
        ui->console->setText("Microprogram : You must write ORG first. \n");
        error = 1;
    }
    lc1=0;
    QStringList riz_f;
    QStringList check1 , check2;
    QStringList riz_f_command;
    microprogram_i instruction;
    int com_f , control_f=0;
if(error !=1)
{

    for(int i=0;i<tcommmands;i++)
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
                                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n No address is needed for the MAP command. \n");
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
                                            ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                                            error = 1;
                                            break;
                                        }
                                }
                                instruction.set_branch(branch[riz_f_command.at(2)]);
                                instruction.set_condition(condition[riz_f_command.at(1)]);
                                instruction.set_write(true);
                                ram_micro.at(lc1)=instruction;
                            }
                        }
                        else
                        {
                            if(riz_f_command.size() > 4)
                            {
                                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                                error = 1;
                                break;
                            }
                            else
                            {
                                if(table_variable.find(riz_f_command.at(3))!=table_variable.end() || riz_f_command.at(3) == "NEXT")
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
                                                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
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
                                        ram_micro.at(lc1)=instruction;
                                    }
                                }
                                else
                                {
                                    ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such label. \n");
                                    error = 1;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such branch. \n");
                        error = 1;
                        break;
                    }
                }
                else
                {
                    ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such condition. \n");
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
                        ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
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
                                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n No address is needed for the MAP command. \n");
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
                                            ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                                            error = 1;
                                            break;
                                        }
                                    }
                                instruction.set_branch(branch[riz_f_command.at(2)]);
                                instruction.set_condition(condition[riz_f_command.at(1)]);
                                instruction.set_write(true);
                                if(instruction.get_f1().get_dec() == instruction.get_f2().get_dec() || instruction.get_f1().get_dec() == instruction.get_f3().get_dec() || instruction.get_f2().get_dec() == instruction.get_f3().get_dec())
                                {
                                    ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n The destination register of the commands is equal. \n");
                                    error = 1;
                                    break;
                                }
                                else
                                {
                                    ram_micro.at(lc1)=instruction;
                                }
                            }
                        }
                        else
                        {
                            if(riz_f_command.size() > 4)
                            {
                                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                                error = 1;
                                break;
                            }
                            else
                            {
                                if(table_variable.find(riz_f_command.at(3))!=table_variable.end() || riz_f_command.at(3) == "NEXT")
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
                                                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
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
                                    if(instruction.get_f1().get_dec() == instruction.get_f2().get_dec() || instruction.get_f1().get_dec() == instruction.get_f3().get_dec() || instruction.get_f2().get_dec() == instruction.get_f3().get_dec())
                                    {
                                        ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n The destination register of the commands is equal. \n");
                                        error = 1;
                                        break;
                                    }
                                    else
                                    {
                                        ram_micro.at(lc1)=instruction;
                                    }
                                }

                                else
                                {
                                    ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such label. \n");
                                    error = 1;
                                    break;
                                }
                            }
                            }
                    }
                    else
                    {
                        ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such branch. \n");
                        error = 1;
                        break;
                    }
                }
                else
                {
                    ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such condition. \n");
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
                                            ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n No address is needed for the MAP command. \n");
                                            error = 1;
                                            break;
                                        }
                                        else
                                        {
                                            instruction.set_branch(branch[riz_f_command.at(2)]);
                                            instruction.set_condition(condition[riz_f_command.at(1)]);
                                            instruction.set_write(true);
                                            if(instruction.get_f1().get_dec() == instruction.get_f2().get_dec() || instruction.get_f1().get_dec() == instruction.get_f3().get_dec() || instruction.get_f2().get_dec() == instruction.get_f3().get_dec())
                                            {
                                                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n The destination register of the commands is equal. \n");
                                                error = 1;
                                                break;
                                            }
                                            else
                                            {
                                                ram_micro.at(lc1)=instruction;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(riz_f_command.size() > 4)
                                        {
                                            ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                                            error = 1;
                                            break;
                                        }
                                        else
                                        {
                                            if(table_variable.find(riz_f_command.at(3))!=table_variable.end() || riz_f_command.at(3) == "NEXT")
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
                                                if(instruction.get_f1().get_dec() == instruction.get_f2().get_dec() || instruction.get_f1().get_dec() == instruction.get_f3().get_dec() || instruction.get_f2().get_dec() == instruction.get_f3().get_dec())
                                                {
                                                    ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n The destination register of the commands is equal. \n");
                                                    error = 1;
                                                    break;
                                                }
                                                else
                                                {
                                                    ram_micro.at(lc1)=instruction;
                                                }
                                            }

                                            else
                                            {
                                                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such label. \n");
                                                error = 1;
                                                break;
                                            }
                                        }
                                        }
                                }
                                else
                                {
                                    ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such branch. \n");
                                    error = 1;
                                    break;
                                }
                            }
                            else
                            {
                                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such condition. \n");
                                error = 1;
                                break;
                            }

                        }
                        else
                        {
                            ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                            error = 1;
                            break;
                        }
                    }
                    else
                    {
                        ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                        error = 1;
                        break;
                    }
                }
                else
                {
                    ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                    error = 1;
                    break;
                }

                break;
            default:
                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
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
     compile_assembly();
}
}

void MainWindow::compile_assembly()
{
    tcommmands = ui->assembly->document()->blockCount();
    QTextDocument *doc = ui->assembly->document();
    ui->console->setText("");
    int  error = 0 , lc1=0 , org=0 , hlt_line=0 , end_line=0;
    bool hlt = false , end=false;
    QStringList riz_command;
    QTextBlock tb;
    for(int i=0;i<tcommmands;i++)
    {
        if(lc1>2048)
        {
            ui->console->setText("ERROR: OVERFLOW RAM!\n");
            error=1;
            break;
        }
    error = 0;
    tb = doc->findBlockByLineNumber(i);
    riz_command = tb.text().split(' ', Qt::SkipEmptyParts);
    if(riz_command.size()==0)
        continue;
    else
    {
        if(riz_command.at(0)[riz_command.at(0).size()-1]==',')
        {
            if(org == 0)
            {
                ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n You must write ORG first. \n");
                error = 1;
                break;
            }
            QString wait="";
            for(int cw=0;cw<riz_command.at(0).size()-1;cw++)
            {
                wait+=riz_command.at(0)[cw];
            }
                table_variable_assembly[wait]=lc1;
                lc1++;
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
                    ui->console->setText("Microprogram : error in line:"+QString::number(i+1)+"\n You need hex number after ORG. \n");
                    error = 1;
                    break;
                }
            }
            else
            {
                if(riz_command.at(0)=="HLT")
                {
                    if(hlt == true)
                    {
                        ui->console->setText("Assembly code entry : Entered code does not have end or hlt \n");
                        error = 1;
                        break;
                    }
                    hlt_line = i;
                    hlt = true;
                }
                else
                    if(riz_command.at(0)=="END")
                    {
                        end_line = i;
                        end = true;
                        break;
                    }
                else
                    if(tb.text()[0] != '/')
                    {
                        lc1++;
                    }
            }
        }
    }
    }
    if(hlt == false || end == false)
    {
        ui->console->setText("Assembly code entry : Entered code does not have end or hlt \n");
        error = 1;
    }
    else
    {
        assembly_i instruction;
        QStringList check1 , check2 , assembel;
        int address;
        for(int i=1;i<=tcommmands;i++)
        {
            if(end_line == i)
                break;
            error = 0;
            tb = doc->findBlockByLineNumber(i);
            check1 = tb.text().split(' ', Qt::SkipEmptyParts);
            if(check1.size()==0 || hlt_line == i)
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
                check2 = riz_command.at(0).split(',', Qt::SkipEmptyParts);
                if(check2.size() == 1)
                    assembel = riz_command.at(0).split(' ' , Qt::SkipEmptyParts);
                else
                    assembel = riz_command.at(1).split(' ' , Qt::SkipEmptyParts);
                if(assembel.size() > 3)
                {
                    ui->console->setText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                    error = 1;
                    break;
                }
                else
                {
                    if(assembel.size() == 2)
                    {
                    if(table_variable.find(assembel.at(0))!=table_variable.end() || assembel.at(0) == "HEX" || assembel.at(0) == "DEC")
                    {
                        if(assembel.at(0) == "HEX")
                        {
                            bool ok=1;
                            address=assembel.at(1).toInt(&ok,16);
                            instruction.set_instruction(129);
                            instruction.set_i(false);
                            instruction.set_address(address);
                            instruction.set_write(true);
                            ram_assembly.at(lc1)=instruction;
                        }
                        else
                        {
                            if(assembel.at(0) == "DEC")
                            {
                                bool ok=1;
                                address=assembel.at(1).toInt(&ok,10);
                                instruction.set_instruction(130);
                                instruction.set_i(false);
                                instruction.set_address(address);
                                instruction.set_write(true);
                                ram_assembly.at(lc1)=instruction;
                            }
                            else
                            {
                                if(table_variable[assembel.at(0)] <64)
                                {
                                    instruction.set_instruction(table_variable[assembel.at(0)]);
                                    instruction.set_i(false);
                                    instruction.set_write(true);
                                    if(table_variable_assembly.find(assembel.at(1))!=table_variable_assembly.end() || isNumber(assembel.at(1)))
                                    {
                                        if(table_variable_assembly.find(assembel.at(1))!=table_variable_assembly.end())
                                            instruction.set_address(table_variable_assembly[assembel.at(1)]);
                                        else
                                        {
                                            bool ok=1;
                                            address=assembel.at(1).toInt(&ok,16);
                                            instruction.set_address(address);
                                        }
                                    }
                                    else
                                    {
                                        ui->console->setText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The address must either be a hex number or its label must be available in the program. \n");
                                        error = 1;
                                        break;
                                    }
                                    ram_assembly.at(lc1)=instruction;
                                }
                                else
                                {
                                    ui->console->setText("Assembly code entry : error in line:"+QString::number(i+1)+"\n You only have access to the houses of less than 64 microprogram memories. \n");
                                    error = 1;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        ui->console->setText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                        error = 1;
                        break;
                    }
                    }
                    else
                    {
                        if(assembel.size() == 1)
                        {
                            if(table_variable.find(assembel.at(0))!=table_variable.end())
                            {

                                if(table_variable[assembel.at(0)] < 64)
                                {
                                    instruction.set_instruction(table_variable[assembel.at(0)]);
                                    instruction.set_i(false);
                                    instruction.set_write(true);
                                    instruction.set_address(131);
                                    ram_assembly.at(lc1)=instruction;
                                }
                                else
                                {
                                    ui->console->setText("Assembly code entry : error in line:"+QString::number(i+1)+"\n You only have access to the houses of less than 64 microprogram memories. \n");
                                    error = 1;
                                    break;
                                }
                            }
                            else
                            {
                                ui->console->setText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                                error = 1;
                                break;
                            }
                        }
                        else
                        {
                            if(table_variable.find(assembel.at(0))!=table_variable.end() )
                            {

                                if(table_variable[assembel.at(0)] <64)
                                {
                                    instruction.set_instruction(table_variable[assembel.at(0)]);
                                    if(assembel.at(2) == "I")
                                        instruction.set_i(true);
                                    else
                                    {
                                        ui->console->setText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                                        error = 1;
                                        break;
                                    }
                                    instruction.set_write(true);
                                    if(table_variable_assembly.find(assembel.at(1))!=table_variable_assembly.end() || isNumber(assembel.at(1)))
                                    {
                                        if(table_variable_assembly.find(assembel.at(1))!=table_variable_assembly.end())
                                            instruction.set_address(table_variable_assembly[assembel.at(1)]);
                                        else
                                        {
                                            bool ok=1;
                                            address=assembel.at(1).toInt(&ok,16);
                                            instruction.set_address(address);
                                        }
                                    }
                                    else
                                    {
                                        ui->console->setText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The address must either be a hex number or its label must be available in the program. \n");
                                        error = 1;
                                        break;
                                    }
                                    ram_assembly.at(lc1)=instruction;
                                }
                                else
                                {
                                    ui->console->setText("Assembly code entry : error in line:"+QString::number(i+1)+"\n You only have access to the houses of less than 64 microprogram memories. \n");
                                    error = 1;
                                    break;
                                }
                            }
                            else
                            {
                                ui->console->setText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                                error = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if(error != 1)
    {
        ui->console->setText("Compilation was successful \n");
    }
}

void MainWindow::on_open_micro_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Text file"), "",tr("microprogram code file (*.bxb)"));
    if (fileName.isEmpty())
        return;
    else {
        ui->Microprogram->clear();
        issaved_micro=fileName;
        ifstream infile;
        infile.open(fileName.toLocal8Bit());
        char tmp[300];
        while(infile.eof()!=true)
        {
            infile.getline(tmp,300);
            ui->Microprogram->insertPlainText(QString::fromStdString(tmp));
            ui->Microprogram->insertPlainText("\n");
        }
    }
}




void MainWindow::on_save_micro_clicked()
{
    if(issaved_micro =="")
    {
       on_actionsave_as_microprogram_triggered();
    }
    else
    {
        ofstream f;
        f.open(issaved_micro.toLocal8Bit(),ios::out);
        f<<ui->Microprogram->toPlainText().toStdString();
        f.flush();
        f.close();

    }
}


void MainWindow::on_actionsave_as_microprogram_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(this,tr("Save"), "",tr("Mytext microprogram file (*.bxb)"));
    if (fileName.isEmpty())
         return;
     else {
        ofstream f;
        f.open(fileName.toLocal8Bit(),ios::out);
        f<<ui->Microprogram->toPlainText().toStdString();
        f.flush();
        f.close();

        issaved_micro=fileName;
    }
}


void MainWindow::on_new_micro_clicked()
{
    ui->Microprogram->clear();
    issaved_micro="";
}


void MainWindow::on_save_assembly_clicked()
{
    if(issaved_assembly =="")
    {
       on_actionsave_as_assembly_code_triggered();
    }
    else
    {
        ofstream f;
        f.open(issaved_assembly.toLocal8Bit(),ios::out);
        f<<ui->Microprogram->toPlainText().toStdString();
        f.flush();
        f.close();

    }
}


void MainWindow::on_actionsave_microprogram_triggered()
{
    on_save_micro_clicked();
}


void MainWindow::on_actionopen_microprogram_triggered()
{
    on_open_micro_clicked();
}


void MainWindow::on_actionsave_as_assembly_code_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save"), "",tr("Mytext assembly file (*.bxb)"));
    if (fileName.isEmpty())
         return;
     else {
        ofstream f;
        f.open(fileName.toLocal8Bit(),ios::out);
        f<<ui->assembly->toPlainText().toStdString();
        f.flush();
        f.close();

        issaved_assembly=fileName;
    }
}


void MainWindow::on_actionsave_assembly_code_triggered()
{
    on_save_assembly_clicked();
}


void MainWindow::on_actionopen_assembly_code_triggered()
{
    on_open_assembly_clicked();
}


void MainWindow::on_actionnew_assembly_code_triggered()
{
    on_new_assembly_clicked();
}


void MainWindow::on_actionnew_microprogram_triggered()
{
    on_new_micro_clicked();
}


void MainWindow::on_actionexit_triggered()
{
    this->close();
}


void MainWindow::on_actioncompile_triggered()
{
    on_pushButton_clicked();
}


void MainWindow::on_open_assembly_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Text file"), "",tr("assembly entry file (*.bxb)"));
    if (fileName.isEmpty())
        return;
    else {
        ui->assembly->clear();
        issaved_assembly=fileName;
        ifstream infile;
        infile.open(fileName.toLocal8Bit());
        char tmp[300];
        while(infile.eof()!=true)
        {
            infile.getline(tmp,300);
            ui->assembly->insertPlainText(QString::fromStdString(tmp));
            ui->assembly->insertPlainText("\n");
        }
    }
}


void MainWindow::on_new_assembly_clicked()
{
    ui->assembly->clear();
    issaved_assembly="";
}


void MainWindow::on_actionabout_project_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("An assembler and hardware simulator for the Mano Basic Computer, a 16 bit computer.\n Programming By: Alireza Falakian \n GitHub link 🔗: https://github.com/falakian/MicroProgram-Simulator");
    msgBox.exec();
}

