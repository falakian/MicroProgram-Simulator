#ifndef MICROPROGRAM_INSTRUCTION_H
#define MICROPROGRAM_INSTRUCTION_H
#include <QString>
#include "instruction_f1.h"
#include "instruction_f2.h"
#include "instruction_f3.h"
class microprogram_i{
private:
    bool write ;
    F1 *f1;
    F2 *f2;
    F3 *f3;
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
        this->f1 = new F1;
        this->f2 = new F2;
        this->f3 = new F3;
    };
    ~microprogram_i()
    {
        delete [] this->f1 ;
        delete [] this->f2 ;
        delete [] this->f3 ;
    };
    void set_f1(F1 f1_code)
    {
       this->f1->set_intersection(f1_code.get_intersection());
       this->f1->set_dec(f1_code.get_dec());
    };
    void set_f2(F2 f2_code)
    {
       this->f2->set_intersection(f2_code.get_intersection());
       this->f2->set_dec(f2_code.get_dec());
    };
    void set_f3(F3 f3_code)
    {
       this->f3->set_intersection(f3_code.get_intersection());
       this->f3->set_dec(f3_code.get_dec());
    };
    void set_condition(int c)
    {
        this->condition = c;
    };
    void set_branch(int b)
    {
        this-> branch = b;
    };
    void set_address(int a)
    {
        this->address=a;
    };
    void set_write(bool a)
    {
        this->write=a;
    };
    F1 get_f1()
    {
        return *this->f1;
    };
    F2 get_f2()
    {
        return *this->f2;
    };
    F3 get_f3()
    {
        return *this->f3;
    };
    int get_int_cd()
    {
        return this->condition;
    };
    int get_int_br()
    {
        return this->branch;
    };
    QString get_cd()
    {
        switch( this->condition)
        {
        case 0:
            return "U";
            break;
        case 1:
            return "I";
            break;
        case 2:
            return "S";
            break;
        case 3:
            return "Z";
            break;
        }
        return "";
    };
    QString get_br()
    {
        switch( this->branch)
        {
        case 0:
            return "JMP";
            break;
        case 1:
            return "CALL";
            break;
        case 2:
            return "RET";
            break;
        case 3:
            return "MAP";
            break;
        }
        return "";
    };
    int get_address()
    {
        return this->address;
    };
    bool get_write()
    {
        return this->write;
    };
    void set(microprogram_i *s)
    {
        this->write = s->write;
        this->condition = s->condition;
        this->branch = s->branch;
        this->address = s->address;
        this->f1->set_intersection(s->f1->get_intersection());
        this->f1->set_dec(s->f1->get_dec());
        this->f2->set_intersection(s->f2->get_intersection());
        this->f2->set_dec(s->f2->get_dec());
        this->f3->set_intersection(s->f3->get_intersection());
        this->f3->set_dec(s->f3->get_dec());
    };
   /* microprogram_i& operator=( microprogram_i *s)
    {
      this->~microprogram_i();
      this->write = s->write;
      this->condition = s->condition;
      this->branch = s->branch;
      this->address = s->address;
      this->f1->set_intersection(s->f1->get_intersection());
      this->f1->set_dec(s->f1->get_dec());
      this->f2->set_intersection(s->f2->get_intersection());
      this->f2->set_dec(s->f2->get_dec());
      this->f3->set_intersection(s->f3->get_intersection());
      this->f3->set_dec(s->f3->get_dec());
      return *this;
    }*/
};

#endif // MICROPROGRAM_INSTRUCTION_H
