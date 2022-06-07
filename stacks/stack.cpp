#include<iostream>
# define N 6
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
    int count()
    {
        if(isempty())
        {
            
            return -1;
        }
        return top +1;
    }
    void change(int indeX,X value)
    {
        if(isempty())
        {
            cout<<"stack under flow !!!"<<endl;
        }
        else if(indeX>top or indeX<0)
        {
            cout<<" indeX not eXist!!!! "<<endl;
        }
        else
        {
            stack[indeX]=value;
        }
    } 
    void display()
    {
        if(isempty())
        {
            cout<<"stack under flow !!!!"<<endl;
        }
        else
        {
            cout<<"elements of stack :\n";
            for(int i=0;i<=top;i++)
            {
                cout<<stack[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    stack<int> s1;
    s1.push(10);
    s1.push(40);
    s1.push(30);
    s1.push(20);
    
    s1.display();

    cout<<"top element : "<<s1.peak()<<endl;
    s1.pop();
    cout<<"size : "<<s1.count()<<endl;;
    s1.display();

    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.peak();
    cout<<s1.count()<<endl;
    s1.push(10);
    s1.push(40);
    s1.push(30);
    cout<<s1.count()<<endl;
    cout<<"*****************************************************************************************\n";
    stack<double> s2;
    s2.push(160.56);
    s2.push(460.4675);
    s2.push(340.67);
    s2.push(2034.4556);
    
    s2.display();

    cout<<"top element : "<<s2.peak()<<endl;
    s2.pop();
    cout<<"size : "<<s2.count()<<endl;;
    s2.display();

    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.peak();
    cout<<s2.count()<<endl;
    s2.push(1450.677);
    s2.push(4035.35677);
    s2.push(304.345555557);
    s2.push(304.345555557);
    s2.push(304.345555557);
    s2.push(304.345555557);
    s2.push(304.345555557);
    
    cout<<s2.count()<<endl;

    return 0;

}