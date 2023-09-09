/*
09.09.23

PROBLEM: 
    Evaluate Reverse Polish Notation   (LeetCode 150: Medium)
        (POSTFIX EXPRESSION EVALUATION)
        
        You are given an array of strings tokens that represents an arithmetic 
            expression in a Reverse Polish Notation.
        Evaluate the expression. Return an integer that represents the value of 
            the expression.

        Note that:
            The valid operators are '+', '-', '*', and '/'.
            Each operand may be an integer or another expression.
            The division between two integers always truncates toward zero.
            There will not be any division by zero.
            The input represents a valid arithmetic expression in a reverse polish notation.
            The answer and all the intermediate calculations can be represented in a 32-bit integer.

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

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // POSTFIX EXPRESSION EVALUATION
        // 09.09.23
        
        stack<int> stk;

        for(auto t: tokens){
            if(isOperator(t)){
                int opd2 = stk.top();
                stk.pop();
                int opd1 = stk.top();
                stk.pop();

                stk.push(operate(opd1, opd2, t));
            }
            else{
                stk.push(stoi(t));
            }
        }

        return stk.top();
    }

    bool isOperator(string t){
        return (t=="*" || t=="/" || t=="+" || t=="-");
    }

    int operate(int a, int b, string oprtr){
        if(oprtr == "*")
            return a*b;

        if(oprtr == "/")
            return a/b;

        if(oprtr == "+")
            return a+b;

        return a-b;
    }
};

// int main(){
//     // provide test cases

//     return 0;
// }