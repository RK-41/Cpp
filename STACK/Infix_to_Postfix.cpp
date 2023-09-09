/*
09.09.23

PROBLEM: Infix to Postfix   (GFG: Medium)
            Given an infix expression in the form of string str, convert it
            to postfix expression.
          
            
SOLUTION:
    SHUNTING YARD ALGORITHM (EDGAR DIJKSTRA)
        SYA is a simple technique for parsing infix exrpessions containing binary 
            operators of varying precedence.

        It assings to each operator its correct operands, taking into account
            the order of precedence.

        It uses a stack to reverse the order of operators in the given
            expression and serves as a storage structure.


        ALGORITHM:
            Traversing the string:
                if an operand is encountered:
                    append it to the postfix expression.
                else:
                    if open parenthesis is encountered:
                        push it to the stack.

                    else if close parenthesis is encountered:
                        while open parenthesis in no encountered (and stack is not empty):
                            append the top of stack (TOS) to the postfix expression, and
                            pop the stack.
                        if top of the stack is a open parenthesis:
                            pop the stack.
                    
                    else: (current character is an operator)
                        while precedence of TOS is greater than that of current operator and TOS != '(':
                            append the TOS to the postfix expression, and
                            pop the stack.
                        push the current character (operator) into the stack.

            Append all the elements of stack (operators) to the postfix expression.
                (this would make the postfix expression complete.)
                    
*/


// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        string ans;
        stack<char> stk;
        
        for(int i=0; i<s.size(); i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                ans += s[i];
            }
            
            else{                
                if(s[i] == '('){
                    stk.push(s[i]);
                }
                
                else if(s[i] == ')'){
                    while(stk.size() && stk.top()!='('){
                        ans += stk.top();
                        stk.pop();
                    }
                    if(stk.size() && stk.top()=='(')
                        stk.pop();
                }
            
                else{
                    while(stk.size() && stk.top()!='(' && precedence(s[i])<=precedence(stk.top())){
                        ans += stk.top();
                        stk.pop();
                    }
                    stk.push(s[i]);
                }
            }
            
        }
        
        
        while(stk.size()){
            ans += stk.top();
            stk.pop();
        }
        
        return ans;
    }
    
    int precedence(char c){
        switch(c){
            case '^':   return 3;
            case '*':   return 2;
            case '/':   return 2;
            case '+':   return 1;
            case '-':   return 1;
            default: return 0;
        }
    }
    
    // bool isOperator(char c){
    //     if(c=='^' || c=='*' || c=='/' || c=='+' || c=='-')
    //         return true;
            
    //     return false;
    // }
};


int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
