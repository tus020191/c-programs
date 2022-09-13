#include<iostream>
using namespace std;

class A
{
public:
    void fun()
    {
        cout<<"parent class 1!!!!\n";
    }

    void hello(int a)
    {
        cout<<"parent class hello!!!!\n";

    }

   
};

class B
{
public:
    //1. function get override if same name is present 
    void fun() // get override 
    {
        cout<<"child class !!!!!!\n";
    }

    //2. here return type and parameter list is different ,but name is same so get ovrride 
    int  hello()
    {
        cout<<"child  class hello!!!!\n"; return 0;

    }

   
};

int main()
{
    B obj;
    obj.fun(); // b class method , not A class method

    obj.hello();  
    
    // obj.hello(5) ;//gives error as hello get override ...

 

    return 0;
}