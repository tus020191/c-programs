#include <iostream>
#include<stack>
#include<vector> 
using namespace std;
template<class X>
class stock_span
{
    int count,n;
    X * arr;
    
public:
   // constructor 
    stock_span(int n) :n(n)
    {
        arr=new X[n]; // dynnamically creating array
        count =1;
        cout<<"enter elements \n"; // accepting elements
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    }
    vector<X> stockarr()
    {
        vector <X> v;
        stack<X> st;
        for(int i=0;i<n;i++)
        {
            count=1;
            if(st.empty())
            {
                st.push(arr[i]);
                v.push_back(count);
                continue;
            }
            while(!st.empty() and st.top()<= arr[i])
            {
                st.pop(); 
                count++;
            }
            v.push_back( ( ( st.empty() ) ? i+1 : count ) );
            st.push(arr[i]);
            
        }
        return v;
    }
    

};
int main() {
	cout<<"GfG!\n";
	int n=7;
	stock_span<int> stock(n);
	vector <int> v=stock.stockarr();
	for(auto e : v)
	{
	    cout<<e<<" ";
	}
	cout<<endl;
	
	
	
	return 0;
}
