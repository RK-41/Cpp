/*
09.09.23 

PROBLEM: Prefix to Infix Conversion     (GFG: Medium)
    
    You are given a string S of size N that represents the prefix form 
        of a valid mathematical expression. 
    Convert it to its infix form.

*/

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        
        stack<string> stk;
        
        for(int i=pre_exp.size()-1; i>=0; i--){
            if(isOperand(pre_exp[i])){
                stk.push(string(1,pre_exp[i]));
            }
            else{
                string a = stk.top();
                stk.pop();
                string b = stk.top();
                stk.pop();
                
                stk.push("(" + a + pre_exp[i] + b + ")");
            }
        }
        
        return stk.top();
    }
    
    bool isOperand(char ch){
        return ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'));
    }
};

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
