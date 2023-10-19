#ifndef INSTRUCTION_F1_H
#define INSTRUCTION_F1_H
#include <QString>
using namespace std;
class F1{
private:
    QString instruction;
    QString dec;

public:
F1(){
    this->instruction="NOP";
    this->dec = "NO OPERATION";
};

F1(QString ins , QString d){
    this->instruction = ins;
    this->dec = d;
};

void set_intersection(QString ins){
    this->instruction = ins;
};

void set_dec(QString d){
    this->dec = d;
};

QString get_intersection(){
    return this->instruction;
};

QString get_dec(){
    return this->dec;
};

};
#endif // INSTRUCTION_F1_H
