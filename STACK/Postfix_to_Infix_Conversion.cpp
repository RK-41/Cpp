// User function Template for C++
/*
09.09.23

PROBLEM: Postfix to Infix Conversion    (GFG: Medium)

    You are given a string that represents the postfix form of a valid 
        mathematical expression. 
    
    Convert it to its infix form.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> stk;
        
        for(int i=0; i<exp.size(); i++){
            if(isOperand(exp[i])){
                stk.push(string(1,exp[i]));
            }
            else{
                string a = stk.top();
                stk.pop();
                string b = stk.top();
                stk.pop();
                
                stk.push(")" + a + exp[i] + b + "(");
            }
        }
        
        string ans = stk.top();
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    bool isOperand(char t){
        return ((t>='A' && t<='Z') || (t>='a' && t<='z') || (t>='0' && t<='9'));
    }
};

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}
