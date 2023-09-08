/* 
06.09.23

PORBLEM: Next Greater Element (GFG: Medium)
        
APPROACH: 
    Using stack to keep track of next greater element.
    
    The array is traversed from the back.
    
    Stack stores the indices of the next greater element.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        // REVERSE OF STOCK SPAN PROBLEM SOLUTION
        vector<long long> nle(n,-1);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            while(st.size() && arr[i]>=arr[st.top()])
                st.pop();
                
            if(st.size())
                nle[i] = arr[st.top()];
                
            st.push(i);
        }
        
        return nle;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
