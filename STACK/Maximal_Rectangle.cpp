/* 
08.09.23

PORBLEM: 
    MAXIMAL RECTANGLE (LeetCode 85: Hard)
    
    Similar to: MAX RECTANGEL (GFG: Hard)
        
APPROACH: 
    Using Concept Applied in the problem 'Largest Rectangular Area in a Histogram'.
        
    Iterating from row 0 to row n-1 of the given matrix and considering every row as 
        the base of a histogram.
            
    On iterating a base(row), if current element is found to be '1' then, it's 
        incremented by it's upper neighbour's value ie, its height gets updated.
            
    After iterating over the current base, it's passed to the function largestRect(),
        which caculates and returns the maximum rectangle area for the base.
            
    The function largestRect() is direct implementation of the above mentioned problem
        ie, 'Largest Rectangular Area in a Histogram'.
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 08.09.23
        
        int r=matrix.size(), c=matrix[0].size();
        vector<int> base, prev;

        for(auto ele:matrix[0])
            base.push_back(ele-'0');

        int ans = largestRect(base);

        prev = base;
        for(int i=1; i<r; i++){
            for(int j=0; j<c; j++){
                base[j] = matrix[i][j]-'0';
            }

            for(int j=0; j<c; j++){
                if(matrix[i][j]=='1')
                    base[j] = prev[j]+1;
                else
                    base[j] = 0;
            }

            ans = max(ans, largestRect(base));
            prev = base;
        }

        return ans;
    }

    int largestRect(vector<int> base){
        int n=base.size(), ans=0;
        vector<int> ps(n,-1), ns(n,n);
        stack<int> stk;
        // ps: previous-smaller
        // ns: next-smaller

        // finding previous smaller elements
        stk.push(0);
        for(int i=1; i<n; i++){
            while(stk.size() && base[i]<=base[stk.top()])
                stk.pop();

            if(stk.size())
                ps[i] = stk.top();

            stk.push(i);
        }

        // emptying the stack
        while(stk.size())
            stk.pop();

        // finding next smaller elements
        stk.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(stk.size() && base[i]<=base[stk.top()])
                stk.pop();

            if(stk.size())
                ns[i] = stk.top();

            stk.push(i);
        }

        // finding max rect area
        for(int i=0; i<n; i++){
            // int width = (ns[i]-i-1) + (i-ps[i]-1) + 1;

            int width = ns[i] - ps[i] - 1;
            int height = base[i];

            ans = max(ans, width*height);        
        }

        return ans;
    }
};