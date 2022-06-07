#include<iostream>
# define N 100
using namespace std;
template<class X>
class stack
{
    int top=-1;
    
    X stack[N];
public :
    bool isempty()
    {

        return  (top==-1) ? true : false;
    }
    bool isfull()
    {
        return (top==N-1) ? true : false ;
    }
    void push(X element)
    {
        if (isfull())
        {
            cout<<"stackoverflow !!!!!!\n";
            
        }
        else
        {
            cout<<"success\n";
            stack[++top]=element;
        }

        
    }
    void pop()
    {
        if (isempty())
        {
            cout<<"stack under flow !!!!!!"<<endl;
            
        }
        else
        {
            stack[top]=0;
            top--;
            cout<<"successfully poped top element !!!!\n";
            
        }
    }
    X peak()
    {
        if(isempty())
        {
            cout<<"stack under flow "<<endl;
            return -1;
        }
        return stack[top];
    }
};

template<class X>
class specialstack: public stack<X>
{
    stack <X> aux;
public:
    void push(X data);
    void pop();
    X get_min();

};
template<class X>
void specialstack<X>:: pop()
{
    stack<X>::pop();
    aux.pop();
}
template<class X>
void specialstack<X>:: push(X data)
{
    
    X y;
    if (stack<X>::isempty())
    {
        stack<X>:: push(data);
        aux.push(data);
        //cout<<"yes\n";
    }
    else
    {
        stack<X>:: push(data);
        y=aux.peak();
        aux.push(((y>data) ?  data : y));
    }

}
template<class X>
X specialstack<X>:: get_min()
{
    return aux.peak();
}

int main()
{
    specialstack< float > s1 ;
    s1.get_min();
    s1.pop();
    s1.peak();
    
    s1.push(19.89);
    s1.push(21.123);
    s1.push(178.67);
    s1.push(15.156);
    s1.push(16.908);

    cout<<s1.get_min()<<endl;
    s1.pop();
    s1.pop();

    cout<<s1.get_min()<<endl;
    s1.pop();
    cout<<s1.get_min()<<endl;
    s1.pop();
    cout<<s1.get_min()<<endl;



}
