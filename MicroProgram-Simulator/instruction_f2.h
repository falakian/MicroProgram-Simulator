#ifndef INSTRUCTION_F2_H
#define INSTRUCTION_F2_H
#include <QString>
using namespace std;
class F2{
private:
    QString instruction;
    QString dec;
public:
F2()
{
    this->instruction="NOP";
    this->dec = "NO OPERATION";
};
F2(QString ins , QString d)
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

QString get_intersection()
{
    return this->instruction;
};

QString get_dec()
{
    return this->dec;
};

};

#endif // INSTRUCTION_F2_H
