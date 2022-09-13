#include<iostream>
using namespace std;

class A
{
    public:
        A()
        {
            cout<<"A ";
        }
};

class B: public A
{
    public:
        B()
        {
            cout<<"B ";
        }
};
class C: public B
{
    public:
        C()
        {
            cout<<"C ";
        }
};


int main()
{
    // first parent constructor is called ,then base class
    /*
    c constructor calls B const. which in turn calls A constr.. hence
    the output A B C
    */
    C objc;


   //  A * ptr ; // making pointer of any class not call constr.

    cout<<endl; 
    A * ptr =new C(); // this calls C constr which in turn call B constr and hence A constr.
    





    cout<<endl; 
    return 0;
}