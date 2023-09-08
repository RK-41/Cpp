/* 
08.09.23

PORBLEM: 
    MAX RECTANGEL (GFG: Hard)
    
    Similar to: MAXIMAL RECTANGLE (LeetCode 85: Hard)
    
APPROACH: 
    Using Concept Applied in the problem 'Maximum Rectangular Area in a Histogram' - GFG.
        
    Iterating from row 0 to row n-1 and considering every row as the base of a histogram.
            
    On iterating a base(row), if current element is found to be '1' then, it's 
        incremented by it's upper neighbour's value ie, its height gets updated.
            
    After iterating over the current base, it's passed to the function largestHist(),
        which caculates and returns the maximum rectangle area for the base.
            
    The function largestHist() is direct implementation of the above mentioned problem
        ie, 'Largest Rectangular Area in a Histogram'.
*/


#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
    
class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        //08.09.23
        
        int ans = largestHist(M[0], m);
        
        for(int i=1; i<n; i++){
            
            for(int j=0; j<m; j++){
                if(M[i][j]==1)
                    M[i][j] += M[i-1][j];
            }
                
            ans = max(ans, largestHist(M[i], m));
        }
        
        return ans;
    }
    
    // Fn which returns largest rectangular area in a histogram
    int largestHist(int base[], int n){
        int ans=0;
        vector<int> ns(n,n), ps(n,-1);
        // ns: next smaller; ps: previous smaller
        stack<int> stk;
        
        // cout<<"In";
        
        // finding previous smaller
        stk.push(0);
        for(int i=1; i<n; i++){
            while(stk.size() && base[i]<=base[stk.top()])
                stk.pop();
                
            if(stk.size())
                ps[i]=stk.top();
            
            stk.push(i);
        }
        
        while(stk.size())
            stk.pop();
            
        // finding next smaller
        stk.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(stk.size() && base[i]<=base[stk.top()])
                stk.pop();
                
            if(stk.size())
                ns[i]=stk.top();
                
            stk.push(i);
        }
        
        // finding max area
        for(int i=0; i<n; i++){
            int curr = base[i];
            
            // adding area to the left of curr
            curr += base[i]*(i-ps[i]-1);
            
            // adding area to the right of curr
            curr += base[i]*(ns[i]-i-1);
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};


int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }

    return 0;
}
