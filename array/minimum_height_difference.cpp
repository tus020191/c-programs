#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int height_min_diff(vector<int> & v,int k)
{
    sort(v.begin(),v.end());
    int ans=v[v.size()-1] - v[0] ;
    int tmpmin,tmpmax;   // maximum difference
    for ( int i = 1; i < v.size()-1; i++)
    {
        /* code */
        if(v[i]>k)
        {
            tmpmin= min(v[0]+ k,v[i]-k);
            tmpmax=max(v[i-1] + k ,v[v.size()-1] -k);
            ans=min(ans,tmpmax - tmpmin);

        }
    }
    return ans;
    
}
int main()
{
    vector <int> v;
    int  k=6; // number by which heights is decreased or increased
    v={7,4,8,8,8,9};
    cout<<(height_min_diff(v,k))<<endl;

    
     
}