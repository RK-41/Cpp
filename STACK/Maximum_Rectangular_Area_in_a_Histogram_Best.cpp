/*
09.09.23

PORBLEM: Maximum Rectangular Area in a Histogram (GFG: Hard)

SOLUTION:
    This is improvised ('Best') solution to the problem.
    The previous ('Better') solution uses a stack along with two vectors of size 'n' 
        and requires three traversals of the array to find the desired result.
        
    The area is calculated using the concept of previous and next smaller elements.
    This program uses a stack to keep track of previous smaller element for each of 
    the element of the array while traversal.
    
    ALGORITHM:
        Iniitialize ans with 0.
        
        Declare a stack.
        
        Traverse the array (arr[i] to arr[n-1]):
            while arr[TOS] >= arr[i]:
                a. store TOS (say tos=stk.top()) and pop the stack,
                b. calculate area considering arr[tos] as the smallest element:
                    if stk.empty() 
                        current_area = arr[tos] * i
                        (this means arr[tos] is smallest in the array) so, curr
                            width would be 'i')
                    else
                        current_area = arr[tos] * (i - stk.top() - 1)
                        (here, 'i-stk.top()-1' is curr width as arr[stk.top()] is
                            previous smaller for arr[i])
                c. store max are in the 'ans' variable
                    ans = max(ans, current_area)
            
        Stack now stores elements which don't've next smaller element.
        Now, traverse the stack:
            a. store TOS (say tos=stk.top()) and pop the stack,
            b. calculate area considering arr[tos] as the smallest element:
                if stk.empty():
                    current_area = arr[tos] * n
                    // curr width would be 'n'
                else:
                    current_area = arr[tos] * (n - stk.top() - 1)
                    (here, 'n-stk.top()-1' is curr width as arr[stk.top()] is
                        previous smaller for arr[i])
            c. store max are in the 'ans' variable
                ans = max(ans, current_area)
            
        Return ans.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        // 09.09.23
        
        stack<long long> stk;
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            // pop while arr[TOS] is >= arr[i] -> finding previsous smaller ele
            while(stk.size() && arr[i]<=arr[stk.top()]){
                int tos = stk.top();
                stk.pop();
                
                long long curr = arr[tos] * (stk.empty()? i : (i - stk.top() - 1));
                
                ans = max(ans, curr);
            }
            stk.push(i);
        }
        
        // Stack now stores elements which don't've next smaller element
        while(stk.size()){
            int tos = stk.top();
            stk.pop();
            
            long long curr = arr[tos] * (stk.empty()? n: (n - stk.top() -1));
            
            ans = max(ans,curr);
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
