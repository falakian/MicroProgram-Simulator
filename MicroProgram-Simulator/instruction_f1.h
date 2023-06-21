#ifndef INSTRUCTION_F1_H
#define INSTRUCTION_F1_H
#include <QString>
using namespace std;
class F1{
private:
    QString instruction;
    QString dec;

public:
F1(){};
F1(QString ins , QString d)
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
#endif // INSTRUCTION_F1_H
