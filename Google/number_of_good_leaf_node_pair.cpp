#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isLeaf(TreeNode *node){
        if(node==NULL){
            return false;
        }
        return node->left==NULL&& node->right==NULL;
    }
    vector<int> helper(TreeNode *node,int &ans,int d){
        if(node==NULL){
            return {};
        }
        if(isLeaf(node)){
            return {1};
        }
        vector<int> l,r;
        l=helper(node->left,ans,d);
        r=helper(node->right,ans,d);
        int m=l.size();
        int n=r.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(l[i]+r[j]<=d){
                    ans++;
                }
            }
        }
        vector<int> arr;
        for(auto &it:l){
            if(it+1<=d){
                arr.push_back(it+1);
            }
        }
        for(auto &it:r){
            if(it+1<=d){
                arr.push_back(it+1);
            }
        }
        return arr;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans=0;
        helper(root,ans,distance);
        return ans;
    }
};