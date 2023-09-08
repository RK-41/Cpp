/* 
06.09.23

PORBLEM: Stock Span Problem (GFG: Medium)
        
APPROACH: 
    Using stack to keep track of previous greater price.
    
    Stack stores the indices of the previous greater price which are used 
        to calculate the span for the current price.
*/


#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to calculate the span of stock's price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
        vector<int> ans;
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(st.size() && price[i]>=price[st.top()])
                st.pop();
                
            if(st.empty())
                ans.push_back(i+1);
            else
                ans.push_back(i-st.top());
                
            st.push(i);
        }
        
        return ans;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

