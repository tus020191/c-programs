#include<iostream>
#include<stack>
#include<vector>
#define N 12 
using namespace std;
template<class X>
stack <X> st; // global stack so that change is reflected at every recursion
template<class X>
 vector< X > v(N);
template<class X>
void insert(X a)
{
    if(st<X>.empty())
    {
        st<X>.push(a);
    }
    else
    {
        int x=st<X>.top();
        st<X>.pop();
        insert<X>(a);
        st<X>.push(x);
        

    }
}
template <class X>
void reverse()
{
    if(! st<X>.empty())
    {
        X x=st<X>.top();
        st<X>.pop();
        reverse<X>();
        insert<X>(x);

    }
}
template<class X>
void add_element(int n)
{
    if(n!=0)
    {

    
        X ele;
        cout<<" enter element :---  ";
        cin>>ele;
        st<X>.push(ele);
        n--;
        add_element<X>(n);
        v<X>[N-1-n]=ele;
    }
  

}
template <class X>
void stackreverse(X z)
{
    
    add_element<X>(N);
    cout<<"st<X>ack before reverse :\n\n\n";
    for(auto ch: v<X>)
    {
        cout<<ch<<"  ";
    }
    cout<<endl;
    reverse<X>();
    cout<<"st<X>ack after reverse :\n";
    v<X>.clear();
    while(!st<X>.empty())
    {
        v<X>.push_back(st<X >.top());
        st<X>.pop();
    }
    for(int i=v<X>.size()-1;i>=0;i--)
    {
        cout<<v<X>[i]<<"  ";
    }
    cout<<endl;
   
}

int main()
{
    
    stackreverse(1);
    return 0;
}
