#include<iostream>
using namespace std;


/*
1.  private member is not inherited ,i,e only public and protected is inherited
2.  visibility mode cane be public,private ,protected
3. in private  mode the public and protected member is inherited as private
4. In protected mode public and protected member is inherited as protected
4. In public mode public member as public and protected member as protected inherited

*/
class A
{
private:
    int a;
public:
    int b;


protected:
    int c;

};


                // visiblity mode private
class B : private A // we can make public and protected also
{
public:

    void set_(int b1,int c1)
    {
        // b and c is inherited as private
        b=b1;
        c=c1;
    }
    void display()
    {
        cout<<"b= "<<b<<endl<<"c= "<<c<<endl;
    }
};


int main()
{
    B obj1;
    obj1.set_(13,78);

    obj1.display();
    //cout<<obj1.b;  give error as b and c are included as private
}
