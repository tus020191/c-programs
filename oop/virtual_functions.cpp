#include<iostream>
using namespace  std;

class A
{
public:

    void nonvirtual()
    {
        cout<<"parent class pointer calls only this nonvertual function\n\n";
    }
    virtual void print()
    {
        cout<<"parent class virtual function !!!!\n";
    }
};
class B: public A
{
public:
    void nonvirtual()
    {
        cout<<"parent class pointer cannot calls base class  nonvertual function\n\n";
    }
    void print()
    {
        cout<<"parent class pointer can call base class  print function\n as it is defined virtual in parent class !!!!\n";
    }
};
int main()
{
    B objb;
    A * ptra=&objb;
    ptra->nonvirtual();

    ptra->print();// pointer of A can now call base class print function...

    return 0;
}