#ifndef ASSEMBLY_INSTRUCTION_H
#define ASSEMBLY_INSTRUCTION_H
#include <QString>

class assembly_i{
private:
    bool write ;
    int instruction;
    bool i;
    int address;
public:
    assembly_i()
    {
        this->write = false;
        this->i=false;
        this->address=131;
    }
    ~assembly_i(){}
    void set_instruction(int c)
    {
        this->instruction = c;
    }
    void set_i(bool b)
    {
        this-> i = b;
    }
    void set_address(int a)
    {
        this->address=a;
    }
    void set_write(bool a)
    {
        this->write=a;
    }
    assembly_i& operator=(const assembly_i& s)
    {
      this->~assembly_i();
      this->write = s.write;
      this->instruction = s.instruction;
      this->i = s.i;
      this->address = s.address;
      return *this;
    }
};
#endif // ASSEMBLY_INSTRUCTION_H
