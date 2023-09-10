/*
10.09.23

GENERATE ALL BINARY STRINGS (GFG: Medium)

https://practice.geeksforgeeks.org/problems/generate-all-binary-strings/1?page=1&sortBy=submissions
*/

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateBinaryStrings(int num){
        //Write your code
        // 10.09.23
        
        if(num==1){
            cout<<"0 1";
            return;
        }
        
        queue<string> q;
        set<string> st;
        
        // creating a string of size 'num'
        string s(num,'0');
        
        q.push(s);    
        st.insert(s);
        
        // Iterating over queue and pushing next valid strings
        while(q.size()){
            cout<<q.front()<<" ";
            
            // operating on string to append "0"
            string t = q.front().substr(1) + "0";
            if(st.find(t)==st.end()){
                q.push(t);
                st.insert(t);
            }
            
            // operating on string to include "1"
            t = q.front().substr(1) + "1";
            if(st.find(t)==st.end() && t[num-2]!='1'){
                q.push(t);
                st.insert(t);
            }
            
            q.pop();
        }
        
        return;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends