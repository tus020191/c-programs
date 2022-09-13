#include<iostream>

using namespace std;
// static variables has their values same for all objects
class A
{
    static int  x; // private
public:
    static int y; // public 
    // cannot be initialized under constructor
   // A(int x_): x(x_){} it will give error as staic member can only be initialized at defination

    A(){}

    // but we can use its value or can modify like x++
   A(int z)
   {
        z=z+(++x);
   }
    void print()
    {
        cout<<x<<" \n";
    }
    // can be changed in methods 
    void set(int x_)
    {
        x=x_;
    }


};
// it is necessary to declar the static members after class in global scope 
// otherwise error will occur 

// declare outside the main all static public and private
int A::x=6;
int A::y=10;

int main()
{
    A a;
    a.print();
    //int A::x=10; will give error
    a.set(90);
    a.print();

    cout<<A::y<<endl;
   // int A::y=100; error

    // here when constructor is called then  previous set value of x i,e x=90 is
    // used and get modified as ++x i,e 91 
   A b(1000);
   b.print();
   a.print(); // same value for all object
    return 0;
}