/* deep copy using copy constructor */

#include<iostream>
using namespace std;

class lst
{
private:
    int *ptr;
    int a,b;
public:
    lst(){ } // default empty constructor

    lst(int a,int b,int pt): a(a),b(b)
    {
        ptr=new int ; // dynamic allocation
        *ptr=pt;
    }

    /* copy constructor */
    lst(lst &obj)  // always pass the refrence of object otherwise error occur
    {
        a=obj.a;
        b=obj.b;
        ptr=new int; // allocating different memory so that
                  // during copy ptr will not point to the memory which the
                  // copying object ptr member point
       // obj.ptr give the address and   *(obj.ptr) give the value of that address
       *ptr= *(obj.ptr);
    }
    ~ lst()
    {
        delete ptr;  //  release the allocated memory
    }

    void display()
    {
        cout<<"a=  "<<a<<"\n"<<"b=  "<<b<<endl<<"ptr= "<<*ptr<<endl;
    }
};
int main()
{
    lst l1(12,15,50);
    lst l2;
    l2=l1; // now copy constructor will be called
    l2.display();
    return 0;
}
