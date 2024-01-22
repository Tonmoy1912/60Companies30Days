#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val,key;
    Node *prev,*next;
    Node(int val,int key){
        this->val=val;
        this->key=key;
        prev=next=NULL;
    }
};

void deleteNode(Node *node,int t){//t=1 ->delete t=0 -> detatch
    node->prev->next=node->next;
    node->next->prev=node->prev;
    if(t){
        delete node;
    } //recently used node
            
}

class LRUCache {
    int capacity,size;
    Node *head;
    unordered_map<int,Node *> map;
    void makeMostRecent(Node *node){
        Node* head_next=head->next;
        node->prev=head;
        node->next=head_next;
        head->next=node;
        head_next->prev=node;
    }
    int deleteLRU(){
        Node* node=head->prev;
        int key=node->key;
        deleteNode(node,1);//delete the node
        return key;
    }
public:
    LRUCache(int capacity) {
        this->capacity=capacity; 
        size=0;  
        head=new Node(-1,-1);
        head->next=head;
        head->prev=head;
    }
    
    int get(int key) {
        if(map[key]==NULL){
            return -1;
        }
        Node *node=map[key];
        deleteNode(node,0);// detatch the node
        makeMostRecent(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(map[key]!=NULL){
            Node *node=map[key];
            node->val=value;
            deleteNode(node,0);//detatch the node
            makeMostRecent(node);
            return ;
        }
        size++;
        if(size>capacity){
            size--;
            int key=deleteLRU();//delete the least recently used node
            map[key]=NULL;//making that the node is not present
        }
        Node *node=new Node(value,key);
        map[key]=node;//marking that the node is present
        makeMostRecent(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */