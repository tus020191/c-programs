#include<iostream>
using namespace std;


class A
{
private:
    int a;
public:
    int b;
    A(int a,int b,int c) : a(a),b(b),c(c)
    {

    }
    int get_b() // function
    {
        return b;
    }
    int get_a()
    {
        return a;
    }

protected:
    int c;

};


                // visiblity mode public
class B : public A
{


private:
    int e,d;
public:
    B(int x,int y,int z,int e,int d) : A(x,y,z),e(e),d(d)
    {
    }
    void set_(int b1,int c1)
    {

        d=b1;
        e=c1;
    }
    void display()
    {
        cout<<"b= "<<b<<endl<<"c= "<<c<<endl<<"d = "<<d<<endl<<" e= "<<e<<endl;
    }
};


int main()
{
    B obj1(12,13,14,50,70);
    //obj1.set_(13,78);
    obj1.display();
    //cout<<obj1.b;  give no error as b and public

    cout<<obj1.get_b()<<endl<<"a=  "<<obj1.get_a()<<endl;


    return 0;
}
