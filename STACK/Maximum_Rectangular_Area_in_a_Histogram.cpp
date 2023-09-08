/* 
07.09.23

PORBLEM: Maximum Rectangular Area in a Histogram (GFG: Hard)
        
APPROACH: 
    Considering each element as smallest height and
        using its previous smaller and next smaller elements to
        find the width, and calculating the area using the height and width.
        
    Storing the indices of next smaller and previous smaller elements
        instead of the elements themselves. This would help in calculating
        the width of the rectangle.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find maximum rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        // 07.09.23
        
        long long ans = 0;
        vector<long long> ps(n,-1), ns(n,n);
        // ps: previous smaller; ns: next smaller
        stack<long long> stk;
        
        // finding next smaller elements
        stk.push(n-1);
        for(int i=n-2; i>=0; i--){
            // while stk contains indices of elements greater than current element
            while(stk.size() && arr[i]<=arr[stk.top()])
                stk.pop();
                
            if(stk.size())
                ns[i] = stk.top();
                
            stk.push(i);
        }
        
        while(stk.size())
            stk.pop();
        
        // finding previous smaller elements
        stk.push(0);
        for(int i=1; i<n; i++){
            while(stk.size() && arr[i]<=arr[stk.top()])
                stk.pop();
                
            if(stk.size())
                ps[i] = stk.top();
                
            stk.push(i);
        }
        
        // iterating over the array to find max rectangular area
        for(int i=0; i<n; i++){
            long long curr=arr[i];
            
            // left side width of the rectangle extends up to previous smaller
            // element's position's immediate right
            curr += (i-ps[i]-1)*arr[i];
            
            // right side width of the rectangle extends up to next smaller
            // element's position's immediate left
            curr += (ns[i]-i-1)*arr[i];
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};


int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
