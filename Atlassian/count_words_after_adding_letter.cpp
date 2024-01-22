#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getHash(string &s){
        int temp=0;
        for(auto &it:s){
            temp=(temp|(1<<(it-'a')));
        }
        return temp;
    }
    int helper(string &str,set<int> &s){
        int hash=getHash(str);
        for(int i=0;i<26;i++){
            if((hash>>i)&1){
                if(s.count(hash^(1<<i))){
                    return 1;
                }
            }
        }
        return 0;
    }
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        set<int> s;
        for(auto &it:startWords){
            s.insert(getHash(it));
        }
        int count=0;
        for(auto &it:targetWords){
            count+=helper(it,s);
        }
        return count;
    }
};