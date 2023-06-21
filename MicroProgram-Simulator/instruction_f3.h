#ifndef INSTRUCTION_F3_H
#define INSTRUCTION_F3_H
#include <QString>
using namespace std;
class F3{
private:
    QString instruction;
    QString dec;
public:
F3()
{
    this->instruction="NOP";
    this->dec = "NO OPERATION";
};
F3(QString ins , QString d)
{
    this->instruction = ins;
    this->dec = d;
};

void set_intersection(QString ins)
{
    this->instruction = ins;
};

void set_dec(QString d)
{
    this->dec = d;
};
};

#endif
