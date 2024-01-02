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
public:
#define ll long long

    struct dum{
        int maxi=INT_MIN;
        int mini=INT_MAX;
        bool t=true;
        int sum=0;
    };

    dum helper(TreeNode* root,int &finall){
        if(root==NULL){
            dum t;
            return t;
        }
        dum l,r;
        dum ans;
        l=helper(root->left,finall);
        r=helper(root->right,finall);
        if(l.t==false||r.t==false){
            ans.t=false;
            ans.sum=max(l.sum,r.sum);
            return ans;
        }
        if(root->val<=l.maxi||root->val>=r.mini){
            ans.t=false;
            ans.sum=max(l.sum,r.sum);
            return ans;
        }
        ans.maxi=max(root->val,r.maxi);
        ans.mini=min(root->val,l.mini);
        ans.sum=root->val+l.sum+r.sum;
        finall=max(finall,ans.sum);
        ans.t=true;
        return ans;
    }

    int maxSumBST(TreeNode* root) {
        int finall=0;
        helper(root,finall);
        return finall;
    }
};