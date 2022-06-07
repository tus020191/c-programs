#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> nges(vector<int> v, int n)
{
    vector<int> v1;
    v1.push_back(0);
    stack<int> s;
    s.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!(s.empty()) && v[i]>=v[s.top()] )
        {
            s.pop();
        }
        v1.push_back((s.empty()) ? 0 : v1[n-s.top()-1]  +1);
        s.push(i);
    }
    reverse(v1.begin(),v1.end());
    return  v1;

}

int main()
{
    int n=8;
    vector <int> v(n);
    v={3,4,2,7,5,8,10,6};
    vector<int > v1=nges(v,n);
    for (auto element : v1)
    {
        /* code */
        cout<<element<<" ";
    }
    cout<<endl;
        
    return 0;
}