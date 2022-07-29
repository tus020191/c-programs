#include<iostream>
using namespace std;

/*
In diamond problem class D has inherited B and C and
but B and C have inherited same class A
so ambiguity occur in D as it inherit the x variable from both B and C
thus to avoid this  B  and C is made virtual class
*/

class A
{
public:
    int x;
};

class B: virtual public A
{

};


class C : public virtual  A
{

};

class D: public B , public C
{
public:

    void set_(int x1)
    {
        x=x1;
    }
    void get_()
    {
        cout<<x<<endl;
    }
};
int main()
{
    D obj;
    obj.set_(45);
    obj.get_();
    return 0;
}
