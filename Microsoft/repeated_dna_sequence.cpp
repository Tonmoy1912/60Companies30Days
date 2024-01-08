#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        unordered_map<string,int> m;
        for(int i=0;i<=n-10;i++){
            string str=s.substr(i,10);
            m[str]++;
        }
        vector<string> ans;
        for(auto &it:m){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};