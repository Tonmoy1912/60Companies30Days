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
    pair<bool,int> helper(TreeNode *root,int start,int &ans){
        if(root==NULL){
            return {false,0};
        }
        pair<bool,int> left,right;
        left=helper(root->left,start,ans);
        right=helper(root->right,start,ans);
        if(root->val==start){
            ans=max({ans,left.second,right.second});
            return {true,1};
        }
        else if(left.first==false && right.first==false){
            return {false,max(left.second,right.second)+1};
        }
        else if(left.first){
            ans=max(ans,left.second+right.second);
            return {true,left.second+1};
        }
        else{
            ans=max(ans,left.second+right.second);
            return {true, right.second+1};
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        helper(root,start,ans);
        return ans;
    }
};