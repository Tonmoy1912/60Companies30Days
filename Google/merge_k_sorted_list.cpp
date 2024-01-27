#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode *merge(ListNode* head1,ListNode* head2){
        ListNode* head=NULL,*temp=NULL;
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        if(head1->val<=head2->val){
            head=temp=head1;
            head1=head1->next;
        }
        else{
            head=temp=head2;
            head2=head2->next;
        }
        while(head1!=NULL&&head2!=NULL){
            if(head1->val<=head2->val){
                temp->next=head1;
                head1=head1->next;
            }
            else{
                temp->next=head2;
                head2=head2->next;
            }
            temp=temp->next;
        }
        if(head1==NULL){
            temp->next=head2;
        }
        else{
            temp->next=head1;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        //int a=lists[0]->val;
        if(n==0){
            return NULL;
        }
        if(n==1){
            return lists[0];
        }
        for(int i=n-2;i>=0;i--){
            lists[i]=merge(lists[i],lists[i+1]);
            //ListNode *head1=lists[i],*head2=lists[i+1];
            
        }
        return lists[0];
    }
};