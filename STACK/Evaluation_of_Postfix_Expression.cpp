/*
09.09.23

PROBLEM: Evaluation of Postfix Expression   (GFG: Easy)
            Given a string S representing a postfix expression, the task is to
            evaluate the expression and find the final value.

            Operators will only include basic arithmetic operators like *, /, + and -.

SOLUTION:
    Using stack to store operands and evaluate them.

    Algorithm:
        Traverse the string:
            if an operand is encountered: 
                push it into the stack.
            if an operator is encountered: 
                a.  pop top two operands,
                b.  evaluate them using current operator, and
                c.  push the result back to stack.

    After traversal is complete, the stack would store the evaluated
        result of the given postfix expression.
            
*/


// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        // 09.09.23
        
        int ans = 0;
        stack<int> stk;
        // stk is used to store operands
        
        for(int i=0; i<S.size(); i++){
            if(S[i]>='0' && S[i]<='9')
                stk.push(S[i]-'0');
            else{
                int opr2 = stk.top();
                stk.pop();
                int opr1 = stk.top();
                stk.pop();
                
                int res = operate(opr1, opr2, S[i]);
                stk.push(res);
            }
        }
        
        return stk.top();
    }
    
    int operate(int a, int b, char opd){
        switch(opd){
            case '^':   return pow(a,b);
            case '*':   return a*b;
            case '/':   return a/b;
            case '+':   return a+b;
            case '-':   return a-b;
        }
    }
};


int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}