#include<iostream>
#include<stack>
#define N 12 
using namespace std;
stack<int> s;
void set(int n)
{
    if(n!=0)
    {
        int ele;
        cin>>ele;
        s.push(ele);
        set(--n);
       // cout<<ele<<endl;
    }
   // else
    //cout<<"elements of stack are :\ntop------->   ";

}
void get(stack<int> t,int n)
{
    if(n!=0)
    {
        int ele=t.top();
        t.pop();
        get(t,--n);
        cout<<ele<<"  ";
    }
    else{
        cout<<"elements of stack : ";
    }

}
stack<int> sortstack(stack<int> st)
{
    stack<int> v;
    while(!st.empty())
    {
        int tmp=st.top();
        st.pop();
        while(!v.empty() and  v.top()<tmp)
        {
            st.push(v.top());
            v.pop();
        }
        v.push(tmp);
    }
    return v;
}
int main()
{
    cout<<"enter elements :\n";
    set(N);
    get(s,N);
    cout<<endl;
    stack<int> s1=sortstack(s);

    get(s1,N);
    cout<<endl;
}
