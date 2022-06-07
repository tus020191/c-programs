#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;
vector<vector<int>> count(vector<int> arr,int x,int n )
{    
    int res=INT_MAX;
    vector<vector<int>> v;
    map<int ,int> m;
   int sum=0;
   for(int i=0;i<n;i++)
   {
       sum+=arr[i];
       if(sum==x)
       {
           
           vector<int> v1;
           for(int j=0;j<=i;j++)
           {
               v1.push_back(arr[j]);
           }
           v.push_back(v1);
           res=min(res,i+1);
           continue;
       }
       if(m.find(sum-x)==m.end())
       {
           m[sum]=i;
           continue;

       }
       vector<int> v2;

       for(int j=m[sum-x]+1;j<=i;j++)
       {
           v2.push_back(arr[j]);
       }
       v.push_back(v2);
       res=min(res,i-m[sum-x]);
       
   }
   cout<<"res=  "<<res<<endl;
   return v;

}
int main()
{
    
    vector<int> arr;
    arr={2,3,-5,6,6,-2,-10,-1};
    
    int x=0;
    vector<vector<int>> v;
    v=count(arr,x,arr.size());
    for(auto i: v)
    {
        for(auto j: i)
        {
            cout<<j<<"  ";
        }
        cout<<endl;
    }
    return 0;
}