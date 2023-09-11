/*
11.09.23    POTD

LeetCode (Medium)
1282. Group the People Given the Group Size They Belong To

https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/?envType=daily-question&envId=2023-09-11
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // 11.09.23 POTD

        // the unordered map will map the elements having same group size to a key (their gr size)
        // the elements having same group size are stored in same queue

        unordered_map<int,queue<int>> grEle;
        vector<vector<int>> ans;

        for(int i=0; i<groupSizes.size(); i++){
            grEle[groupSizes[i]].push(i);
        }

        for(auto &g: grEle){
            int grSize = g.first;
            auto q = g.second;

            // if q.size == grSize, the q doesn't need to be divided into sub-groups
            if(q.size() == grSize){
                vector<int> v;

                while(q.size()){
                    v.push_back(q.front());
                    q.pop();
                }

                ans.push_back(v);
            }
            else{
            // else, the q has to be divided into sub-groups of size 'grSize'

                while(q.size()){
                    vector<int> v;
                    int sz = grSize;

                    // making a sub-group of size 'grSize'
                    while(sz--){
                        v.push_back(q.front());
                        q.pop();
                    }

                    sz = grSize;
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }
};