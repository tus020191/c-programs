#include<iostream>
using namespace std;

int x=5;
namespace e
{
    int x=15;
    int y=20;
    namespace e1
    {
        int x=10;
    } 
}

int main()
{
    // for printing global x
    cout<<"global x: "<<x<<endl; // or ::x
    using namespace e;
    // here we need to specify the x scope as x is defined in global also 
    // so ,without scope it is ambiguos which x we are calling .
    cout<<"x inside the e: "<<e::x<<endl;

    // for y no ambugity so can be called directly 
    cout<<"y inside namespace  e : "<<y<<endl;

    using namespace e::e1;
    cout<<"X inside e1 "<<e::e1::x<<endl;
    return 0;
}