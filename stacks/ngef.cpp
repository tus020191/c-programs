#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;
// program to find the next greater frequency element 
/*    
   for eg if      arr={12,13,15,12,16,18,16,16,19}
   then answer will be 
   {16,12,12,16-1,-1,-1,-1}
   as after 12 next greater frequency element is 16
after 13 next greater frequency element is 12 , and so on 

*/

vector <int> ngef(vector<int> v, int n)
{
    map <int,int> m;
    for(int i=0;i<n;i++)
    {
        m[v[i]]++; // calculating frequency of each elements
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
