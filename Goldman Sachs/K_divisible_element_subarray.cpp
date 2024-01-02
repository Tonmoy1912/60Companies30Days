#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    int x;
    unordered_map<int,TrieNode*> children;
    bool isTerminal;
    TrieNode(int x){
        this->x=x;
        isTerminal=false;
    }
};

class Trie{
    TrieNode* root;
    TrieNode *cur;
    public:
    Trie(){
        root=new TrieNode(-1);
        cur=root;
    }
    void reset(){
        cur=root;
    }
    bool put(int x){
        if(cur->children.count(x)==0){
            cur->children[x]=new TrieNode(x);
        }
        cur=cur->children[x];
        bool ans=!(cur->isTerminal);
        cur->isTerminal=true;
        return ans;
    }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        int ans=0;
        Trie t;
        for(int i=0;i<n;i++){
            int count=0;
            t.reset();
            for(int j=i;j>=0;j--){
                if(nums[j]%p==0){
                    count++;
                    if(count>k){
                        break;
                    }
                }
                ans+=t.put(nums[j]);
            }
        }
        return ans;
    }
};