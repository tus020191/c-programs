#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

vector <int> ngef(vector<int> v, int n)
{
    map <int,int> m;
    for(int i=0;i<n;i++)
    {
        m[v[i]]++;
    }
    vector<int> v1(n);
    v1[n-1]=-1;
    stack<int> s;
    s.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!(s.empty()) && m[v[i]] >= m[v[s.top()]] )
        {
            s.pop();
        }
        v1[i]=(s.empty()) ? -1 :  v[s.top()];
        s.push(i);
    }
   
     return  v1;
}
int main()
{
    int n=10;
    vector <int> v(n);
    v={1,1,1,2,2,2,2,11,3,3};
    vector<int > v1=ngef(v,n);
    for (auto element : v1)
    {
        /* code */
        cout<<element<<" ";
    }
    cout<<endl;
    return 0;
}