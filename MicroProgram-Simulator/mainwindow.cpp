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
    for(int i=0 ; i<128 ; i++)
    {
        ram_micro[i] = new microprogram_i();
    }
    ram_assembly.resize(2048);
    for(int i=0 ; i<2048 ; i++)
    {
        ram_assembly[i] = new assembly_i();
    }
    setWindowIcon(QIcon(":/new/prefix1/pic/icon.png"));
    ui->save_assembly->setIcon(QIcon(":/new/prefix1/pic/save.png"));
    ui->open_assembly->setIcon(QIcon(":/new/prefix1/pic/open.png"));
    ui->new_assembly->setIcon(QIcon(":/new/prefix1/pic/new.png"));
    ui->save_micro->setIcon(QIcon(":/new/prefix1/pic/save.png"));
    ui->open_micro->setIcon(QIcon(":/new/prefix1/pic/open.png"));
    ui->new_micro->setIcon(QIcon(":/new/prefix1/pic/new.png"));
    //ui->next_step->setIcon(QIcon(":/new/prefix1/pic/stepnext.png"));
    ui->next_step->setEnabled(false);
    //ui->continue_2->setIcon(QIcon(":/new/prefix1/pic/continue.png"));
    ui->continue_2->setEnabled(false);
    //ui->stop->setIcon(QIcon(":/new/prefix1/pic/stop.png"));
    ui->stop->setEnabled(false);
    //ui->restart->setIcon(QIcon(":/new/prefix1/pic/restart.png"));
    ui->restart->setEnabled(false);
    ui->save_assembly->setIconSize(QSize(35, 35));
    ui->open_assembly->setIconSize(QSize(35, 35));
    ui->new_assembly->setIconSize(QSize(35, 35));
    ui->save_micro->setIconSize(QSize(35, 35));
    ui->open_micro->setIconSize(QSize(35, 35));
    ui->new_micro->setIconSize(QSize(35, 35));
    //ui->next_step->setIconSize(QSize(35, 35));
    //ui->continue_2->setIconSize(QSize(35,35));
    //ui->restart->setIconSize(QSize(35,35));
    //ui->stop->setIconSize(QSize(35,35));
    //ui->RAM_table->horizontalHeader()->resizeSections(QHeaderView::Interactive);
    //ui->Microprogram_table->horizontalHeader()->resizeSections(QHeaderView::Interactive);
    printTable_RAM();
    printTable_Microgram();
    table_variable_ins[-1] = "HEX";
    table_variable_ins[-2] = "DEC";
    bitset<16> zero1(0);
    bitset<11> zero2(0);
    bitset<7> zero3(0);
    bitset<7> fetch(64);
    AR=zero2;
    DR=zero1;
    AC=zero1;
    PC=zero2;
    SBR=zero3;
    CAR=fetch;
    ui->ac->setText(QString::fromStdString(AC.to_string()));
    ui->dr->setText(QString::fromStdString(DR.to_string()));
    ui->pc->setText(QString::fromStdString(PC.to_string()));
    ui->ar->setText(QString::fromStdString(AR.to_string()));
    ui->sbr->setText(QString::fromStdString(SBR.to_string()));
    ui->car->setText(QString::fromStdString(CAR.to_string()));
    ui->f1->setText("NOP");
    ui->f2->setText("NOP");
    ui->f3->setText("NOP");
    connect(ui->Microprogram->verticalScrollBar(), &QScrollBar::valueChanged,ui->micro_number->verticalScrollBar(),&QScrollBar::setValue);
    connect(ui->micro_number->verticalScrollBar(), &QScrollBar::valueChanged,ui->Microprogram->verticalScrollBar(),&QScrollBar::setValue);
    connect(ui->assembly->verticalScrollBar(), &QScrollBar::valueChanged,ui->assembel_number->verticalScrollBar(),&QScrollBar::setValue);
    connect(ui->assembel_number->verticalScrollBar(), &QScrollBar::valueChanged,ui->assembly->verticalScrollBar(),&QScrollBar::setValue);
    ui->assembly->setLineWrapMode(QPlainTextEdit::LineWrapMode::NoWrap);
    ui->Microprogram->setLineWrapMode(QPlainTextEdit::LineWrapMode::NoWrap);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printTable_RAM()
{
        ui->RAM_table->setRowCount(0);
        ui->RAM_table->horizontalHeader()->setStyleSheet("color: black");
        for(int i=0;i<2048;i++)
        {
            QString address = QString::number( i, 16 ).toUpper();
            QTableWidgetItem *itmaddr = new QTableWidgetItem();
            QTableWidgetItem *itmHex = new QTableWidgetItem();
            itmaddr->setText(address);
            itmHex->setText("0000");
            ui->RAM_table->insertRow(i);
            ui->RAM_table->setItem(i,0,itmaddr);
            ui->RAM_table->setItem(i,2,itmHex);
        }
};

void MainWindow::printTable_Microgram()
{
        ui->Microprogram_table->setRowCount(0);
        ui->Microprogram_table->horizontalHeader()->setStyleSheet("color: black");
        for(int i=0;i<128;i++)
        {
            QString address = QString::number( i, 16 ).toUpper();
            QTableWidgetItem *itmaddr = new QTableWidgetItem(address);
            QTableWidgetItem *itmHex = new QTableWidgetItem("00000");
            ui->Microprogram_table->insertRow(i);
            ui->Microprogram_table->setItem(i,0,itmaddr);
            ui->Microprogram_table->setItem(i,7,itmHex);
        }
};

void MainWindow::printrow_ram_micro(int lc)
{
    ui->Microprogram_table->setItem(lc,1,new QTableWidgetItem(ram_micro.at(lc)->get_f1().get_intersection()));
    ui->Microprogram_table->setItem(lc,2,new QTableWidgetItem(ram_micro.at(lc)->get_f2().get_intersection()));
    ui->Microprogram_table->setItem(lc,3,new QTableWidgetItem(ram_micro.at(lc)->get_f3().get_intersection()));
    ui->Microprogram_table->setItem(lc,4,new QTableWidgetItem(ram_micro.at(lc)->get_cd()));
    ui->Microprogram_table->setItem(lc,5,new QTableWidgetItem(ram_micro.at(lc)->get_br()));
    QTableWidgetItem *itAD = new QTableWidgetItem();
    QTableWidgetItem *itmHex = new QTableWidgetItem();
    bitset<3> f1_bit((command_f(ram_micro.at(lc)->get_f1().get_intersection() , 0)/4));
    bitset<3> f2_bit((command_f(ram_micro.at(lc)->get_f2().get_intersection() , 1)/4));
    bitset<3> f3_bit((command_f(ram_micro.at(lc)->get_f3().get_intersection() , 2)/4));
    bitset<2> cd_bit(ram_micro.at(lc)->get_int_cd());
    bitset<2> br_bit(ram_micro.at(lc)->get_int_br());
    bitset<7> ad_bit(ram_micro.at(lc)->get_address());
    bitset<20> micro_instruction(string(f1_bit.to_string()+f2_bit.to_string()+f3_bit.to_string()+cd_bit.to_string()+br_bit.to_string()+ad_bit.to_string()));
    itAD->setText(QString::fromStdString(ad_bit.to_string()));
    QString hex = dectohex(micro_instruction.to_ulong());
    itmHex->setText(hex);

    ui->Microprogram_table->setItem(lc,6,itAD);
    ui->Microprogram_table->setItem(lc,7,itmHex);
};

void MainWindow::printrow_ram(int lc)
{
    ui->RAM_table->setItem(lc,1,new QTableWidgetItem(table_variable_ins[ram_assembly.at(lc)->get_instruction()]));
    QTableWidgetItem *itmHex = new QTableWidgetItem();
    bitset<1> i_bit(ram_assembly.at(lc)->get_i());
    bitset<4> ins_bit(ram_assembly.at(lc)->get_instruction());
    if(ram_assembly.at(lc)->get_instruction()<0)
    {
       bitset<4> temp (string("0000")) ;
       ins_bit = temp;
    }
    bitset<11> ad_bit(ram_assembly.at(lc)->get_address());
    bitset<16> micro_instruction(string(i_bit.to_string()+ins_bit.to_string()+ad_bit.to_string()));
    QString hex = dectohex(micro_instruction.to_ulong());
    itmHex->setText(hex);
    ui->RAM_table->setItem(lc,2,itmHex);

};

bool MainWindow::fullSubtractor(bool b1, bool b2, bool& borrow)
{
    bool diff;
    if (borrow) {
        diff = !(b1 ^ b2);
        borrow = !b1 || (b1 && b2);
    }
    else {
        diff = b1 ^ b2;
        borrow = !b1 && b2;
    }
    return diff;
}
// Function to calculate difference between two bitsets
bitset<16> MainWindow::bitsetSubtract(bitset<16> x, bitset<16> y)
{
    bool borrow = false;
    // bitset to store the sum of the two bitsets
    bitset<16> ans;
    for (int i = 0; i < 16; i++) {
        ans[i] = fullSubtractor(x[i], y[i], borrow);
    }
    return ans;
}

bool MainWindow::fullAdder(bool b1, bool b2, bool& carry)
{
    bool sum = (b1 ^ b2) ^ carry;
    carry = (b1 && b2) || (b1 && carry) || (b2 && carry);
    return sum;
}
// Function to add two bitsets
bitset<16> MainWindow::bitsetAdd(bitset<16>& x, bitset<16>& y)
{
    bool carry = false;
    // bitset to store the sum of the two bitsets
    bitset<16> ans;
    for (int i = 0; i < 16; i++) {
        ans[i] = fullAdder(x[i], y[i], carry);
    }
    return ans;
}

bitset<7> MainWindow::bitsetAdd_7bit(bitset<7>& x, bitset<7>& y)
{
    bool carry = false;
    // bitset to store the sum of the two bitsets
    bitset<7> ans;
    for (int i = 0; i < 7; i++) {
        ans[i] = fullAdder(x[i], y[i], carry);
    }
    return ans;
}


QString MainWindow::dectohex(int n)
{
    // ans string to store hexadecimal number
    QString ans = "";

    while (n != 0) {
        // remainder variable to store remainder
        int rem = 0;

        // ch variable to store each character
        char ch;
        // storing remainder in rem variable.
        rem = n % 16;

        // check if temp < 10
        if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 55;
        }

        // updating the ans string with the character variable
        ans += ch;
        n = n / 16;
    }

    // reversing the ans string to get the final result
    int i = 0, j = ans.size() - 1;
    while(i <= j)
    {
      swap(ans[i], ans[j]);
      i++;
      j--;
    }
    return ans;
};

bitset<11> MainWindow::bit_16_to_11( bitset<16> a)
{
    bitset<11> res;
    for(int k=0; k<11; k++)
    {
        res[k] = a[k];
    }
    return res;
};

bitset<16> MainWindow::bit_11_to_16( bitset<11> a)
{
    bitset<16> res(0);
    for(int k=0; k<11; k++)
    {
        res[k] = a[k];
    }
    return res;
};

bitset<11> MainWindow::incpc(bitset<11> a)
{

    bool carry = false;
    // bitset to store the sum of the two bitsets
    bitset<11> y(string("00000000001"));
    bitset<11> ans;
    for (int i = 0; i < 11; i++) {
        ans[i] = fullAdder(a[i], y[i], carry);
    }
    return ans;
};

bitset<4> MainWindow::opcode( bitset<16> a)
{
    bitset<4> res;
    for(int k=11; k<15; k++)
    {
        res[k-11] = a[k];
    }
    return res;
};

bitset<7> MainWindow::maping( bitset<16> a)
{
    bitset<1> z(0);
    bitset<7> res;
    res[0] = z[0];
    res[1] = z[0];
    res[6] = z[0];
    res[2] = a[11];
    res[3] = a[12];
    res[4] = a[13];
    res[5] = a[14];
    return res;
};

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
        ui->console->insertPlainText("ERROR: OVERFLOW MICROPROGRAM RAM!\n");
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
                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n You must write ORG first. \n");
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
                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n The label cannot be the word NEXT. \n");
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
                    ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n You need hex number after ORG. \n");
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
        ui->console->insertPlainText("Microprogram : You must write ORG first. \n");
        error = 1;
    }
    lc1=0;
    QStringList riz_f;
    QStringList check1 , check2;
    QStringList riz_f_command;
    microprogram_i *instruction = new microprogram_i;
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
        if(tb.text()[0] != '/')
        {
            riz_command = tb.text().split('/', Qt::SkipEmptyParts);
            check2 = riz_command.at(0).split(':', Qt::SkipEmptyParts);
            if(check2.size() == 1)
                riz_f = check2.at(0).split(',' , Qt::SkipEmptyParts);
            else
                riz_f = check2.at(1).split(',' , Qt::SkipEmptyParts);
            switch( riz_f.size())
            {
            case 1:
                riz_f_command=riz_f.at(0).split(' ' , Qt::SkipEmptyParts);
                if(isCondition(riz_f_command.at(1)))
                {
                    if(isBranch(riz_f_command.at(2)))
                    {
                        if(riz_f_command.at(2) == "MAP" || riz_f_command.at(2) == "RET")
                        {
                            if(riz_f_command.size() > 3)
                            {
                                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n No address is needed for the MAP command. \n");
                                error = 1;
                                break;
                            }
                            else
                            {
                                com_f = command_f(riz_f_command.at(0) , 0);
                                if(com_f % 4 == 0)
                                {
                                    instruction->set_f1(symbol_f1.at((com_f/4)));
                                    instruction->set_f2(symbol_f2.at(0));
                                    instruction->set_f3(symbol_f3.at(0));
                                }
                                else
                                {
                                    if(com_f % 4 == 1)
                                    {
                                        instruction->set_f1(symbol_f1.at(0));
                                        instruction->set_f2(symbol_f2.at((com_f/4)));
                                        instruction->set_f3(symbol_f3.at(0));
                                    }
                                    else
                                        if(com_f % 4 == 2)
                                        {
                                            instruction->set_f1(symbol_f1.at(0));
                                            instruction->set_f2(symbol_f2.at(0));
                                            instruction->set_f3(symbol_f3.at((com_f/4)));
                                        }
                                        else
                                        {
                                            ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                                            error = 1;
                                            break;
                                        }
                                }
                                instruction->set_branch(branch[riz_f_command.at(2)]);
                                instruction->set_condition(condition[riz_f_command.at(1)]);
                                instruction->set_address(0);
                                instruction->set_write(true);
                                ram_micro.at(lc1)->set(instruction);
                            }
                        }
                        else
                        {
                            if(riz_f_command.size() > 4)
                            {
                                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
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
                                    instruction->set_f1(symbol_f1.at((com_f/4)));
                                    instruction->set_f2(symbol_f2.at(0));
                                    instruction->set_f3(symbol_f3.at(0));
                                    }
                                    else
                                    {
                                        if(com_f % 4 == 1)
                                        {
                                            instruction->set_f1(symbol_f1.at(0));
                                            instruction->set_f2(symbol_f2.at((com_f/4)));
                                            instruction->set_f3(symbol_f3.at(0));
                                        }
                                        else
                                            if(com_f % 4 == 2)
                                            {
                                                instruction->set_f1(symbol_f1.at(0));
                                                instruction->set_f2(symbol_f2.at(0));
                                                instruction->set_f3(symbol_f3.at((com_f/4)));
                                            }
                                            else
                                            {
                                                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                                                error = 1;
                                                break;
                                            }
                                    }
                                    instruction->set_branch(branch[riz_f_command.at(2)]);
                                    instruction->set_condition(condition[riz_f_command.at(1)]);
                                    instruction->set_write(true);
                                    if(riz_f_command.at(3) != "NEXT")
                                    {
                                        instruction->set_address(table_variable[riz_f_command.at(3)]);
                                    }
                                    else
                                    {
                                        instruction->set_address(lc1+1);
                                    }
                                    ram_micro.at(lc1)->set(instruction);
                                }
                                else
                                {
                                    ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such label. \n");
                                    error = 1;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such branch. \n");
                        error = 1;
                        break;
                    }
                }
                else
                {
                    ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such condition. \n");
                    error = 1;
                    break;
                }
                break;
            case 2:
                com_f = command_f(riz_f.at(0) , 0);
                if(com_f % 4 == 0)
                {
                    instruction->set_f1(symbol_f1.at((com_f/4)));
                    control_f = 1;
                }
                else
                {
                    if(com_f % 4 == 1)
                    {
                        instruction->set_f1(symbol_f1.at(0));
                        instruction->set_f2(symbol_f2.at((com_f/4)));
                        control_f = 2;
                    }
                    else
                    {
                        ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                        error = 1;
                        break;
                    }
                }
                riz_f_command=riz_f.at(1).split(' ' , Qt::SkipEmptyParts);
                if(isCondition(riz_f_command.at(1)))
                {
                    if(isBranch(riz_f_command.at(2)))
                    {
                        if(riz_f_command.at(2) == "MAP" || riz_f_command.at(2) == "RET")
                        {
                            if(riz_f_command.size() > 3)
                            {
                                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n No address is needed for the MAP command. \n");
                                error = 1;
                                break;
                            }
                            else
                            {
                                com_f = command_f(riz_f_command.at(0) , control_f);
                                if(com_f % 4 == 1 && control_f == 1)
                                {
                                    instruction->set_f2(symbol_f2.at((com_f/4)));
                                    instruction->set_f3(symbol_f3.at(0));
                                }
                                else
                                    if(com_f % 4 == 2 && control_f == 1)
                                    {
                                        instruction->set_f2(symbol_f2.at(0));
                                        instruction->set_f3(symbol_f3.at((com_f/4)));
                                    }
                                    else
                                    {
                                        if((com_f % 4 == 2 && control_f == 2))
                                        {
                                            instruction->set_f3(symbol_f3.at((com_f/4)));
                                        }
                                        else
                                        {
                                            ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                                            error = 1;
                                            break;
                                        }
                                    }
                                instruction->set_branch(branch[riz_f_command.at(2)]);
                                instruction->set_condition(condition[riz_f_command.at(1)]);
                                instruction->set_address(0);
                                instruction->set_write(true);
                                if(instruction->get_f1().get_dec() == instruction->get_f2().get_dec() || instruction->get_f1().get_dec() == instruction->get_f3().get_dec() || instruction->get_f2().get_dec() == instruction->get_f3().get_dec())
                                {
                                    ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n The destination register of the commands is equal. \n");
                                    error = 1;
                                    break;
                                }
                                else
                                {
                                    ram_micro.at(lc1)->set(instruction);
                                }
                            }
                        }
                        else
                        {
                            if(riz_f_command.size() > 4)
                            {
                                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
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
                                        instruction->set_f2(symbol_f2.at((com_f/4)));
                                        instruction->set_f3(symbol_f3.at(0));
                                    }
                                    else
                                    {
                                        if(com_f % 4 == 2 && control_f == 1)
                                        {
                                            instruction->set_f2(symbol_f2.at(0));
                                            instruction->set_f3(symbol_f3.at((com_f/4)));
                                        }
                                        else
                                        {
                                            if((com_f % 4 == 2 && control_f == 2))
                                            {
                                                instruction->set_f3(symbol_f3.at((com_f/4)));
                                            }
                                            else
                                            {
                                                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                                                error = 1;
                                                break;
                                            }
                                        }
                                    }
                                    instruction->set_branch(branch[riz_f_command.at(2)]);
                                    instruction->set_condition(condition[riz_f_command.at(1)]);
                                    instruction->set_write(true);
                                    if(riz_f_command.at(3) != "NEXT")
                                    {
                                        instruction->set_address(table_variable[riz_f_command.at(3)]);
                                    }
                                    else
                                    {
                                        instruction->set_address(lc1+1);
                                    }
                                    if(instruction->get_f1().get_dec() == instruction->get_f2().get_dec() || instruction->get_f1().get_dec() == instruction->get_f3().get_dec() || instruction->get_f2().get_dec() == instruction->get_f3().get_dec())
                                    {
                                        ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n The destination register of the commands is equal. \n");
                                        error = 1;
                                        break;
                                    }
                                    else
                                    {
                                        ram_micro.at(lc1)->set(instruction);
                                    }
                                }

                                else
                                {
                                    ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such label. \n");
                                    error = 1;
                                    break;
                                }
                            }
                            }
                    }
                    else
                    {
                        ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such branch. \n");
                        error = 1;
                        break;
                    }
                }
                else
                {
                    ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such condition. \n");
                    error = 1;
                    break;
                }
                break;
            case 3:
                com_f = command_f(riz_f.at(0) , 0);
                if(com_f % 4 == 0)
                {
                    instruction->set_f1(symbol_f1.at((com_f/4)));
                    com_f = command_f(riz_f.at(1) , 1);
                    if(com_f % 4 == 1)
                    {
                        instruction->set_f2(symbol_f2.at((com_f/4)));
                        riz_f_command=riz_f.at(2).split(' ' , Qt::SkipEmptyParts);
                        com_f = command_f(riz_f_command.at(0) , 1);
                        if(com_f % 4 == 2)
                        {
                            instruction->set_f3(symbol_f3.at((com_f/4)));
                            if(isCondition(riz_f_command.at(1)))
                            {
                                if(isBranch(riz_f_command.at(2)))
                                {
                                    if(riz_f_command.at(2) == "MAP" || riz_f_command.at(2) == "RET")
                                    {
                                        if(riz_f_command.size() > 3)
                                        {
                                            ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n No address is needed for the MAP command. \n");
                                            error = 1;
                                            break;
                                        }
                                        else
                                        {
                                            instruction->set_branch(branch[riz_f_command.at(2)]);
                                            instruction->set_condition(condition[riz_f_command.at(1)]);
                                            instruction->set_write(true);
                                            instruction->set_address(0);
                                            if(instruction->get_f1().get_dec() == instruction->get_f2().get_dec() || instruction->get_f1().get_dec() == instruction->get_f3().get_dec() || instruction->get_f2().get_dec() == instruction->get_f3().get_dec())
                                            {
                                                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n The destination register of the commands is equal. \n");
                                                error = 1;
                                                break;
                                            }
                                            else
                                            {
                                                ram_micro.at(lc1)->set(instruction);
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(riz_f_command.size() > 4)
                                        {
                                            ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                                            error = 1;
                                            break;
                                        }
                                        else
                                        {
                                            if(table_variable.find(riz_f_command.at(3))!=table_variable.end() || riz_f_command.at(3) == "NEXT")
                                            {
                                                instruction->set_branch(branch[riz_f_command.at(2)]);
                                                instruction->set_condition(condition[riz_f_command.at(1)]);
                                                instruction->set_write(true);
                                                if(riz_f_command.at(3) != "NEXT")
                                                {
                                                    instruction->set_address(table_variable[riz_f_command.at(3)]);
                                                }
                                                else
                                                {
                                                    instruction->set_address(lc1+1);
                                                }
                                                if(instruction->get_f1().get_dec() == instruction->get_f2().get_dec() || instruction->get_f1().get_dec() == instruction->get_f3().get_dec() || instruction->get_f2().get_dec() == instruction->get_f3().get_dec())
                                                {
                                                    ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n The destination register of the commands is equal. \n");
                                                    error = 1;
                                                    break;
                                                }
                                                else
                                                {
                                                    ram_micro.at(lc1)->set(instruction);
                                                }
                                            }

                                            else
                                            {
                                                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such label. \n");
                                                error = 1;
                                                break;
                                            }
                                        }
                                        }
                                }
                                else
                                {
                                    ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such branch. \n");
                                    error = 1;
                                    break;
                                }
                            }
                            else
                            {
                                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n There is no such condition. \n");
                                error = 1;
                                break;
                            }

                        }
                        else
                        {
                            ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                            error = 1;
                            break;
                        }
                    }
                    else
                    {
                        ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                        error = 1;
                        break;
                    }
                }
                else
                {
                    ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                    error = 1;
                    break;
                }

                break;
            default:
                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n F1, F2, F3 entered incorrectly. \n");
                error = 1;
                break;
            }
            if(error)
                break;
            else
            {
                printrow_ram_micro(lc1);
                lc1++;
            }
        }
    }
}
if(error != 1)
{
    ui->console->insertPlainText("Microprogram was compiled successfully \n");
     compile_assembly();
}
}

void MainWindow::compile_assembly()
{
    tcommmands = ui->assembly->document()->blockCount();
    QTextDocument *doc = ui->assembly->document();
    int  error = 0 , lc1=0 , org=0 , hlt_line=0 , end_line=0;
    bool hlt = false , end=false;
    QStringList riz_command;
    QTextBlock tb;
    for(int i=0;i<tcommmands;i++)
    {
        if(lc1>2048)
        {
            ui->console->insertPlainText("ERROR: OVERFLOW RAM!\n");
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
                ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n You must write ORG first. \n");
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
                    ui->console->insertPlainText("Microprogram : error in line:"+QString::number(i+1)+"\n You need hex number after ORG. \n");
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
                        ui->console->insertPlainText("Assembly code entry : Entered code does not have end or hlt \n");
                        error = 1;
                        break;
                    }
                    hlt_line = i;
                    //HLT = lc1;
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
        ui->console->insertPlainText("Assembly code entry : Entered code does not have end or hlt \n");
        error = 1;
    }
    else
    {
        assembly_i* instruction = new assembly_i();
        QStringList check1 , check2 , assembel;
        int address;
        for(int i=0;i<tcommmands;i++)
        {
            if(end_line == i)
                break;
            error = 0;
            tb = doc->findBlockByLineNumber(i);
            check1 = tb.text().split(' ', Qt::SkipEmptyParts);
            if(check1.size()==0)
                continue;
            if( hlt_line == i)
            {
                HLT = lc1;
                continue;
            }
            if(check1.at(0)=="ORG")
            {
                bool ok=1;
                lc1=check1.at(1).toInt(&ok,16);
                continue;
            }
            if(tb.text()[0] != '/')
            {
                riz_command = tb.text().split('/', Qt::SkipEmptyParts);
                check2 = riz_command.at(0).split(',', Qt::SkipEmptyParts);
                if(check2.size() == 1)
                    assembel = check2.at(0).split(' ' , Qt::SkipEmptyParts);
                else
                {
                    assembel = check2.at(1).split(' ' , Qt::SkipEmptyParts);
                    if(assembel.size() == 0)
                    {
                        assembel = check2.at(0).split(' ' , Qt::SkipEmptyParts);
                    }
                }
                if(assembel.size() > 3)
                {
                    ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
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
                            instruction->set_instruction(-1);
                            instruction->set_i(false);
                            instruction->set_address(address);
                            instruction->set_write(true);
                            ram_assembly.at(lc1)->set(instruction);
                        }
                        else
                        {
                            if(assembel.at(0) == "DEC")
                            {
                                bool ok=1;
                                address=assembel.at(1).toInt(&ok,10);
                                instruction->set_instruction(-2);
                                instruction->set_i(false);
                                instruction->set_address(address);
                                instruction->set_write(true);
                                ram_assembly.at(lc1)->set(instruction);
                            }
                            else
                            {
                                if(table_variable[assembel.at(0)] < 64)
                                {
                                    if(table_variable[assembel.at(0)]%4 == 0)
                                    {
                                        instruction->set_instruction(table_variable[assembel.at(0)]);
                                        table_variable_ins[table_variable[assembel.at(0)]] = assembel.at(0);
                                        instruction->set_i(false);
                                        instruction->set_write(true);
                                        if(table_variable_assembly.find(assembel.at(1))!=table_variable_assembly.end() || isNumber(assembel.at(1)))
                                        {
                                            if(table_variable_assembly.find(assembel.at(1))!=table_variable_assembly.end())
                                                instruction->set_address(table_variable_assembly[assembel.at(1)]);
                                            else
                                            {
                                                bool ok=1;
                                                address=assembel.at(1).toInt(&ok,16);
                                                instruction->set_address(address);
                                            }
                                        }
                                        else
                                        {
                                            ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The address must either be a hex number or its label must be available in the program. \n");
                                            error = 1;
                                            break;
                                        }
                                        ram_assembly.at(lc1)->set(instruction);
                                    }
                                    else
                                    {
                                        ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n This command is in a location of the micro program memory that you do not have permission to access. \n");
                                        error = 1;
                                        break;
                                    }
                                }
                                else
                                {
                                    ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n You only have access to the houses of less than 64 microprogram memories. \n");
                                    error = 1;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
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
                                    if(table_variable[assembel.at(0)]%4 == 0)
                                    {
                                        instruction->set_instruction(table_variable[assembel.at(0)]);
                                        instruction->set_i(false);
                                        instruction->set_write(true);
                                        instruction->set_address(0);
                                        table_variable_ins[table_variable[assembel.at(0)]] = assembel.at(0);
                                        ram_assembly.at(lc1)->set(instruction);
                                    }
                                    else
                                    {
                                        ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n This command is in a location of the micro program memory that you do not have permission to access. \n");
                                        error = 1;
                                        break;
                                    }
                                }
                                else
                                {
                                    ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n You only have access to the houses of less than 64 microprogram memories. \n");
                                    error = 1;
                                    break;
                                }
                            }
                            else
                            {
                                if(table_variable_assembly.find(assembel.at(0))!=table_variable_assembly.end())
                                {
                                    instruction->set_instruction(-3);
                                    instruction->set_i(false);
                                    instruction->set_write(true);
                                    instruction->set_address(0);
                                    ram_assembly.at(lc1)->set(instruction);
                                }
                                else
                                {
                                    ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                                    error = 1;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            if(table_variable.find(assembel.at(0))!=table_variable.end() )
                            {

                                if(table_variable[assembel.at(0)] <64)
                                {
                                    if(table_variable[assembel.at(0)]%4 == 0)
                                    {
                                        instruction->set_instruction(table_variable[assembel.at(0)]);
                                        if(assembel.at(2) == "I")
                                            instruction->set_i(true);
                                        else
                                        {
                                            ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                                            error = 1;
                                            break;
                                        }
                                        instruction->set_write(true);
                                        if(table_variable_assembly.find(assembel.at(1))!=table_variable_assembly.end() || isNumber(assembel.at(1)))
                                        {
                                            if(table_variable_assembly.find(assembel.at(1))!=table_variable_assembly.end())
                                                instruction->set_address(table_variable_assembly[assembel.at(1)]);
                                            else
                                            {
                                                bool ok=1;
                                                address=assembel.at(1).toInt(&ok,16);
                                                instruction->set_address(address);
                                            }
                                        }
                                        else
                                        {
                                            ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The address must either be a hex number or its label must be available in the program. \n");
                                            error = 1;
                                            break;
                                        }
                                        table_variable_ins[table_variable[assembel.at(0)]] = assembel.at(0);
                                        ram_assembly.at(lc1)->set(instruction);
                                    }
                                    else
                                    {
                                        ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n This command is in a location of the micro program memory that you do not have permission to access. \n");
                                        error = 1;
                                        break;
                                    }
                                }
                                else
                                {
                                    ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n You only have access to the houses of less than 64 microprogram memories. \n");
                                    error = 1;
                                    break;
                                }
                            }
                            else
                            {
                                ui->console->insertPlainText("Assembly code entry : error in line:"+QString::number(i+1)+"\n The syntax is incorrect. \n");
                                error = 1;
                                break;
                            }
                        }
                    }
                }
            }
            if(error != 1)
            {
                printrow_ram(lc1);
                lc1++;
            }
        } 
    }
    if(error != 1)
    {
        ui->console->insertPlainText("Compilation was successful \n");
        compiled=1;
    }
};

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
};




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
};


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
};


void MainWindow::on_new_micro_clicked()
{
    ui->Microprogram->clear();
    issaved_micro="";
};


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
};


void MainWindow::on_actionsave_microprogram_triggered()
{
    on_save_micro_clicked();
};


void MainWindow::on_actionopen_microprogram_triggered()
{
    on_open_micro_clicked();
};


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
};


void MainWindow::on_actionsave_assembly_code_triggered()
{
    on_save_assembly_clicked();
};


void MainWindow::on_actionopen_assembly_code_triggered()
{
    on_open_assembly_clicked();
};


void MainWindow::on_actionnew_assembly_code_triggered()
{
    on_new_assembly_clicked();
};


void MainWindow::on_actionnew_microprogram_triggered()
{
    on_new_micro_clicked();
};


void MainWindow::on_actionexit_triggered()
{
    this->close();
};


void MainWindow::on_actioncompile_triggered()
{
    on_pushButton_clicked();
};


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
};


void MainWindow::on_new_assembly_clicked()
{
    ui->assembly->clear();
    issaved_assembly="";
};


void MainWindow::on_actionabout_project_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("An assembler and hardware simulator for the Mano Basic Computer, a 16 bit computer.\n Programming By: Alireza Falakian \n GitHub link 🔗: https://github.com/falakian/MicroProgram-Simulator");
    msgBox.exec();
};

int  MainWindow::run_instruction_microprogram(int l , bool id)
{
    if(!ram_micro.at(l)->get_write())
    {
        ui->console->insertPlainText("error runtime : error in line:"+QString::number(l)+"\n It refers to the empty house of memory. \n");
        return -1 ;
    }
    bitset<11> AR_T=AR;
    bitset<16> DR_T=DR;
    bitset<16> AC_T=AC;
    bitset<11> PC_T=PC;
    bitset<7> SBR_T=SBR;
    bitset<7> CAR_T=CAR;
    bitset<7> AD_T(ram_micro.at(l)->get_address());
    bitset<16> inc(1);
    bitset<7> inccar(1);
    bitset<16> XOR(string("1111111111111111"));
    if(ram_micro.at(l)->get_f1().get_intersection() == "ADD")
        AC_T = bitsetAdd(AC, DR);
    else
        if(ram_micro.at(l)->get_f1().get_intersection() == "CLRAC")
            AC_T.reset() ;
        else
            if(ram_micro.at(l)->get_f1().get_intersection() == "INCAC")
                AC_T = bitsetAdd(AC, inc);
            else
                if(ram_micro.at(l)->get_f1().get_intersection() == "DRTAC")
                    AC_T = DR ;
                else
                    if(ram_micro.at(l)->get_f1().get_intersection() == "DRTAR")
                        AR_T = bit_16_to_11(DR);
                    else
                        if(ram_micro.at(l)->get_f1().get_intersection() == "PCTAR")
                            AR_T = PC;
                        else
                            if(ram_micro.at(l)->get_f1().get_intersection() == "WRITE")
                            {
                                int address = bit_16_to_11(DR).to_ulong();
                                bool i;
                                if(DR[15] == 0)
                                    i = false;
                                else
                                    i = true;
                                int ins = opcode(DR).to_ulong();
                                int line = AR.to_ulong();
                                ram_assembly.at(line)->set_address(address);
                                ram_assembly.at(line)->set_i(i);
                                ram_assembly.at(line)->set_instruction(ins);
                                ram_assembly.at(line)->set_write(true);
                                printrow_ram(line);
                            }
                            else
                            {
                                if(ram_micro.at(l)->get_f1().get_intersection() != "NOP")
                                {
                                    ui->console->insertPlainText("error runtime : error in line:"+QString::number(l)+"\n The f1 command was not recognized. \n");
                                    return -1 ;
                                }
                            }
    if(ram_micro.at(l)->get_f2().get_intersection() == "SUB")
        AC_T = bitsetSubtract(AC , DR);
    else
        if(ram_micro.at(l)->get_f2().get_intersection() == "OR")
           AC_T = AC | DR ;
        else
            if(ram_micro.at(l)->get_f2().get_intersection() == "AND")
                AC_T = AC & DR;
            else
                if(ram_micro.at(l)->get_f2().get_intersection() == "READ")
                {
                    int line = AR.to_ulong();
                    if(ram_assembly.at(line)->get_write())
                    {
                        bitset<1> i_bit(ram_assembly.at(line)->get_i());
                        bitset<4> ins_bit(ram_assembly.at(line)->get_instruction());
                        bitset<11> ad_bit(ram_assembly.at(line)->get_address());
                        bitset<16> micro_instruction(string(i_bit.to_string()+ins_bit.to_string()+ad_bit.to_string()));
                        DR_T = micro_instruction;
                    }
                    else
                    {
                        ui->console->insertPlainText("error runtime : error in line:"+QString::number(l)+"\n You want to read the contents of the empty memory house. \n");
                        return -1;
                    }
                }
                else
                    if(ram_micro.at(l)->get_f2().get_intersection() == "ACTDR")
                        DR_T = AC ;
                    else
                        if(ram_micro.at(l)->get_f2().get_intersection() == "INCDR")
                            DR_T = bitsetAdd(DR, inc);
                        else
                            if(ram_micro.at(l)->get_f2().get_intersection() == "PCTDR")
                                DR_T = bit_11_to_16(PC);
                            else
                            {
                                if(ram_micro.at(l)->get_f2().get_intersection() != "NOP")
                                {
                                    ui->console->insertPlainText("error runtime : error in line:"+QString::number(l)+"\n The f2 command was not recognized. \n");
                                    return -1;
                                }
                            }
    if(ram_micro.at(l)->get_f3().get_intersection() == "XOR")
        AC_T = AC ^ DR;
    else
        if(ram_micro.at(l)->get_f3().get_intersection() == "COM")
            AC_T = AC ^ XOR;
        else
            if(ram_micro.at(l)->get_f3().get_intersection() == "SHL")
                AC_T = AC <<= 1 ;
            else
                if(ram_micro.at(l)->get_f3().get_intersection() == "SHR")
                    AC_T = AC >>= 1 ;
                else
                    if(ram_micro.at(l)->get_f3().get_intersection() == "INCPC")
                        PC_T = incpc(PC);
                    else
                        if(ram_micro.at(l)->get_f3().get_intersection() == "ARTPC")
                            PC_T = AR ;
                        else
                        {
                            if(ram_micro.at(l)->get_f3().get_intersection() != "NOP")
                            {
                                ui->console->insertPlainText("error runtime : error in line:"+QString::number(l)+"\n The f3 command was not recognized. \n");
                                return -1;
                            }
                        }
    if((ram_micro.at(l)->get_int_cd() == 1 && id) || (ram_micro.at(l)->get_int_cd() == 0) || (ram_micro.at(l)->get_int_cd() == 2 && AC[15] == inc[0]) || (ram_micro.at(l)->get_int_cd() == 3 && AC.to_ulong() == 0) )
    {
        if(ram_micro.at(l)->get_int_br() == 0 )
        {
            CAR_T = AD_T ;
        }
        else
        {
            if(ram_micro.at(l)->get_int_br() == 1)
            {
                CAR_T = AD_T;
                SBR_T = bitsetAdd_7bit(CAR , inccar);
            }
            else
            {
                if(ram_micro.at(l)->get_int_br() == 2)
                {
                    CAR_T = SBR;
                }
                else
                {
                    if(ram_micro.at(l)->get_int_br() == 3)
                    {
                        CAR_T = maping(DR);
                    }
                    else
                    {
                        ui->console->insertPlainText("error runtime : error in line:"+QString::number(l)+"\n branch is wrong. \n");
                        return -1;
                    }
                }
            }
        }
    }
    else
    {
        CAR_T = bitsetAdd_7bit(CAR , inccar);
    }
    AR=AR_T;
    DR=DR_T;
    AC=AC_T;
    PC=PC_T;
    SBR=SBR_T;
    CAR=CAR_T;
    ui->ac->setText(QString::fromStdString(AC.to_string()));
    ui->dr->setText(QString::fromStdString(DR.to_string()));
    ui->pc->setText(QString::fromStdString(PC.to_string()));
    ui->ar->setText(QString::fromStdString(AR.to_string()));
    ui->sbr->setText(QString::fromStdString(SBR.to_string()));
    ui->car->setText(QString::fromStdString(CAR.to_string()));
    ui->f1->setText(ram_micro.at(l)->get_f1().get_intersection());
    ui->f2->setText(ram_micro.at(l)->get_f2().get_intersection());
    ui->f3->setText(ram_micro.at(l)->get_f3().get_intersection());
    for(int j=0 ; j<8 ;j++ )
    {
        ui->Microprogram_table->item(l , j)->setBackground(QColor(37, 40, 45));
    }
    return 0;
};

void MainWindow::run_instruction()
{

};


void MainWindow::on_Microprogram_blockCountChanged(int newBlockCount)
{
    ui->micro_number->setRowCount(0);
    ui->micro_number->setColumnCount(1);
    for(int i=0;i<newBlockCount;i++)
    {
        ui->micro_number->insertRow(i);
        QTableWidgetItem *n = new QTableWidgetItem(QString::number(i+1).toUpper());
        ui->micro_number->setItem(i,0,n);
    }
   ui->micro_number->verticalScrollBar()->setValue(ui->Microprogram->verticalScrollBar()->value());
};




void MainWindow::on_assembly_blockCountChanged(int newBlockCount)
{
    ui->assembel_number->setRowCount(0);
    ui->assembel_number->setColumnCount(1);
    for(int i=0;i<newBlockCount;i++)
    {
        ui->assembel_number->insertRow(i);
        QTableWidgetItem *n = new QTableWidgetItem(QString::number(i+1).toUpper());
        ui->assembel_number->setItem(i,0,n);
    }
   ui->assembel_number->verticalScrollBar()->setValue(ui->assembly->verticalScrollBar()->value());
}


void MainWindow::on_pushButton_4_clicked()
{
    PC.reset();
    AR.reset();
    DR.reset();
    AC.reset();
    SBR.reset();
    CAR.reset();
    resetRam();
    printTable_Microgram();
    printTable_RAM();
    ui->console->setText("");
    compiled=0;
    ui->run->setEnabled(true);
    ui->debug->setEnabled(true);
}

void  MainWindow::resetRam()
{
    for(int i=0 ; i<128 ; i++)
    {
        ram_micro[i] = new microprogram_i();
    }
    for(int i=0 ; i<2048 ; i++)
    {
        ram_assembly[i] = new assembly_i();
    }
}
