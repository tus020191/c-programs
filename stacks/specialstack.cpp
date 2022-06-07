#include<iostream>
using namespace std;
# define N 100
template <class X>
class stack
{

    int top=-1;
    X arr[N]={0};
public:
    bool empty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
    bool full()
    {
        return (top==N-1) ?true: false;  
    }
    void pop()
    {
        if(empty()==1) {cout<<-1<<endl; }
        else
        {
            top--;
        }
    }
    void push(X data)
    {
        if((full()==1)) 
        { cout<<"overflow \n" ;
        }
        else
        {
             arr[++top]=data;
        } 
    }
    X peak()
    {
        return (empty()==1) ? -1 : arr[top];
    }
    
    int size()
    {
        return top+1;
    }
    
};


template<class X>
class specialstack 
{
    stack<X> s;
    X minele ;   
public:
    void push(X data);
    X pop();
    X get_min();
    void display();

};
template<class X>
X specialstack<X>:: pop()
{
    X tp=-1;
    if(! s.empty())
    {
        if(s.peak()>minele)
        {
            tp=s.peak();
        }
        else
        {
            tp=minele;
            minele= minele*2 - s.peak();
            s.pop();
        }
    }
    return tp;
}
template<class X>
void specialstack<X>:: push(X data)
{
   if(s.empty())
   {
       s.push(data);
       minele=data;
   }
   if(! s.full())
   {
       if(data>minele)
       {
           s.push(data);
       }
       else
       {
           s.push(2*data -minele);
           minele=data;
       }
   }
   else{
       cout<<-1<<endl;
   }

}
template<class X>
X specialstack<X>:: get_min()
{
    if(! s.empty()){
        return minele;
    }
    return -1;
}

     
 
int main()
{
    specialstack <int > s;
    s.push(23);
    s.push(80);
    s.push(50);
    s.push(19);
    //s.display();
    cout<<"poped element = "<<s.pop()<<endl;
    cout<<"minimum ="<<s.get_min()<<endl;
    //s.display();
    s.push(1);
    //s.display();
    cout<<"minimum ="<<s.get_min()<<endl;
    
    s.push(7);
    s.push(4);
    //s.display();
    cout<<"poped element ="<<s.pop()<<endl;
    //s.display();
    s.push(14);
    s.push(120);
    s.push(10);
    s.push(-40);

    //s.display();
    cout<<"minimum ="<< s.get_min()<<endl;

    
}