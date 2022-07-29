#include<iostream>
using namespace std;
template <class X,class Y>
class complexnum
{
private:
    X real;
    Y imag;
public:
    complexnum(){} // default empty constructor
    complexnum(X real,Y imag) : real(real),imag(imag)
    {

    }

    // overloading uniary - operator
    complexnum operator -()
    {
        imag=-imag;
        return (*this); // this is the pointer to current object
    }
    void display()
    {
        cout<<real<<" "<<imag<<"j"<<endl;
    }


};
int main()
{
    complexnum<int,int> c1(12,17) ;
    c1=-c1; // default copy constructor will run
    c1.display();

    complexnum<int,float> c2(12,17.67f) ;
    c2=-c2; // default copy constructor will run
    c2.display();
    complexnum<int,int> c3 ; // empty constructor will be called
    c3=-c1;
    c3.display();
    return 0;
}
