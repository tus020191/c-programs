#include<iostream>
using namespace std;
template<class X,class Y>
class complexnumber
{
private:
    X a;
    Y b;
public:
    // remember to make friend function as when
    // << operator is called then on left side cout is there
    // but cout is of different class ....
    template<class u,class v>
    friend ostream & operator <<(ostream & ,complexnumber<u,v> &);

    template<class u,class v>
    friend istream & operator >>(istream & ,complexnumber<u,v> &);
};

template<class u,class v>
ostream & operator << (ostream & print, complexnumber<u,v> & obj)
{
    print<<obj.a<<" + "<<obj.b<<"j"<<endl;
    return print;
}

template<class u,class v>
istream & operator >> (istream & input, complexnumber<u,v> & obj)
{
    cout<<"enter real part : ";
    input>>obj.a;
    cout<<"enter imaginary part : ";
    input>>obj.b;
    return input;

}

int main()
{
    complexnumber<int,float> c1;
    cin>>c1;
    cout<<c1;
}
