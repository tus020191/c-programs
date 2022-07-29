#include<iostream>
#include<string>
using namespace std;

template<class X>
class A
{
private:
    X a,b;
public:
    void set_a(X a1){
         a=a1;
    }
    void set_b(X b1);

    X get_a()
    {
        return a;
    }

       X get_b()
    {
        return b;
    }

    A increase()
    {
        A<X> tmp;  // or we can write A tmp as already A is deduced as X type
        tmp.a=a+1;
        tmp.b=b+1;
        return tmp;
    }
    A decrease();

    // for making friend class always remember to make different
    // template
    template<class u>
    friend A<u> square(A<u> &);

};
// declaring function outsinde of generic class
template<class X>
void A<X>::set_b(X b1)
{
    b=b1;
}

// declaring outside the class
//here it is necessary to give the type of class in declaration
template<class X>
A<X> A<X>::decrease()
{
    A tmp; // or we can write A<X> as here tmp is of A type which is already deduced as X type
    tmp.a=a-1;
    tmp.b=b-1;
    return tmp;
}
template<class u>
A<u> square(A<u> & obj)
{
    A<u> tmp;
    tmp.a=obj.a * obj.a;
    tmp.b=obj.b * obj.b;
    return tmp;
}

int main()
{
    A<int> a1;
    a1.set_a(4);
    a1.set_b(7);
    A<int >a2;
    a2=a1.increase();
    cout<<a2.get_a()<<" "<<a2.get_b()<<endl;

    a2=a1.decrease();
    cout<<a2.get_a()<<" "<<a2.get_b()<<endl;

    a2=square(a1);
    cout<<a2.get_a()<<" "<<a2.get_b()<<endl;
}

