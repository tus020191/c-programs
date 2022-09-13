#include<iostream>
using namespace std;
# define  br    cout<<endl

class A
{
    public:
    A()
    {
        cout<<"A ";
    }

    // non virtual destructor can not calls its chils class destructor 
    // when an pointer of parent class pointing to base class is deleted ..
        ~A()
        {
            cout<<"~A ";
        }
};

class B: public A
{
    public:
        B()
        {
            cout<<"B ";
        }

        // this virtual destructor  calls its chils class destructor 
        virtual ~B()
        {
            cout<<"~B ";
        }
};
class C: public B
{
    public:
        C()
        {
            cout<<"C ";
        }
        ~C()
        {
            cout<<"~C ";
        }
};


int main()
{
    // first child class destructor is called which in turn calls parent ~A

    A* ptr=new B();br;
    // this will call only A destructor.... 
    delete ptr; br;

    B * ptrb=new C(); br;
    // this calls  first C destructor as B destructor is defined as virtual 
    //and then  B destructor and this  in turn calls A destructor ....
    delete ptrb; br;
    return 0;
}