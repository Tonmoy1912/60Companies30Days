#include<bits/stdc++.h>
using namespace std;

struct Node{
    bool terminal;
    vector<Node*> arr;
    Node(){
        terminal=false;
        arr.resize(26);
    }
};

class WordDictionary {
    Node *root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node *cur=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            int c=word[i]-'a';
            if(cur->arr[c]==NULL){
                cur->arr[c]=new Node();
            }
            cur=cur->arr[c];
        }
        cur->terminal=true;
    }
    bool helper(string &word,Node *node,int i,int n){
        if(i>=n){
            return node->terminal;
        }
        if(word[i]=='.'){
            for(int t=0;t<26;t++){
                if(node->arr[t]!=NULL){
                    if(helper(word,node->arr[t],i+1,n)){
                        return true;
                    }
                }
            }
            return false;
        }
        int c=word[i]-'a';
        if(node->arr[c]==NULL){
            return false;
        }
        return helper(word,node->arr[c],i+1,n);
    }
    
    bool search(string word) {
        return helper(word,root,0,word.size());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */