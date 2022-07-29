
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
    //always remember to create another template if making friend function
    template<class x,class y>
    friend complexnum<x,y> operator +(complexnum<x,y> &c1,complexnum<x,y> &c2);

    void display()
    {
        cout<<real<<" "<<imag<<"j"<<endl;
    }


};
template <class x,class y>
complexnum<x,y> operator+(complexnum<x,y> &c1,complexnum<x,y> &c2)
{
    complexnum<x,y> tmp;
    tmp.real=c1.real + c2.real;
    tmp.imag=c1.imag + c2.imag;
    return tmp;
}
int main()
{
    complexnum<int,int> c1(12,17) ;

    c1.display();

    complexnum<int,int> c2(18,16) ;

    c2.display();
    complexnum<int,int> c3 ; // empty constructor will be called
    c3=c1+c2;
    c3.display();
    return 0;
}
