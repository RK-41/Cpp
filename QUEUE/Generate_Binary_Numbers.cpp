/*
10.09.23

GENERATE BINARY NUMBERS (GFG: Easy)

https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1?page=1&sortBy=submissions
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	// 10.09.23
	
	if(N==0)    return {"0"};
	
	vector<string> ans;
	queue<string> q;
	q.push("1");
	
	while(N--){
	    ans.push_back(q.front());
	    q.push(q.front()+"0");
	    q.push(q.front()+"1");
	    q.pop();
	}
	
	return ans;
}


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends