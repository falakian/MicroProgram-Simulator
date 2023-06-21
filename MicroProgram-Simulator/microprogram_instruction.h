#ifndef MICROPROGRAM_INSTRUCTION_H
#define MICROPROGRAM_INSTRUCTION_H
#include <QString>
#include "instruction_f1.h"
#include "instruction_f2.h"
#include "instruction_f3.h"
class microprogram_i{
private:
    bool write ;
    F1 f1;
    F2 f2;
    F3 f3;
    int condition;
    int branch;
    int address;
public:
    microprogram_i()
    {
        this->write = false;
        this->condition=0;
        this->branch=0;
        this->address=0;
    }
    void set_f1(F1 f1_code)
    {
       this->f1.set_intersection(f1_code.get_intersection());
       this->f1.set_dec(f1_code.get_dec());
    }
    void set_f2(F2 f2_code)
    {
       this->f2.set_intersection(f2_code.get_intersection());
       this->f2.set_dec(f2_code.get_dec());
    }
    void set_f3(F3 f3_code)
    {
       this->f3.set_intersection(f3_code.get_intersection());
       this->f3.set_dec(f3_code.get_dec());
    }
    void set_condition(int c)
    {
        this->condition = c;
    }
    void set_branch(int b)
    {
        this-> branch = b;
    }
    void set_address(int a)
    {
        this->address=a;
    }
    void set_write(bool a)
    {
        this->write=a;
    }
};

#endif // MICROPROGRAM_INSTRUCTION_H
