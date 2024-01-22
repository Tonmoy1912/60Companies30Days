#include<bits/stdc++.h>
using namespace std;

struct Node{
    string name;
    bool dead;
    vector<Node *>child;
    Node(string name){
        this->name=name;
        dead=false;
    }
};

class ThroneInheritance {
    Node *root;
    unordered_map<string,Node*> m;
    void helper(Node *root,vector<string> &ans){
        if(!root->dead){
            ans.push_back(root->name);
        }
        for(auto it:root->child){
            helper(it,ans);
        }
    }
public:
    ThroneInheritance(string kingName) {
        root=new Node(kingName);
        m[kingName]=root;
    }
    
    void birth(string parentName, string childName) {
        Node *parent=m[parentName];
        parent->child.push_back(new Node(childName));
        m[childName]=parent->child.back();
    }
    
    void death(string name) {
        m[name]->dead=true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        helper(root,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */