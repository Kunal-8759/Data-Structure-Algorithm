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
    ListNode* findMiddle(ListNode* head){
        ListNode* prevSlow=NULL;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            prevSlow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return prevSlow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* Prev=NULL;
        ListNode* Curr=head;
        ListNode* Next=head->next;

        while(Curr!=NULL){
            Curr->next=Prev;
            Prev=Curr;
            Curr=Next;
            if(Next!=NULL) Next=Next->next;
        }
        return Prev;
    }
    void reorderList(ListNode* head) {
        if(head->next==NULL) return;
        ListNode* leftmiddle=findMiddle(head);
        ListNode* middle=leftmiddle->next;
        leftmiddle->next=NULL;
        ListNode* newHead=reverse(middle);

        ListNode* c=new ListNode(-1);
        ListNode* tc=c;

        ListNode* ta=head;
        ListNode* tb=newHead;

        while(ta!=NULL && tb!=NULL){
            tc->next=ta;
            tc=ta;
            ta=ta->next;

            tc->next=tb;
            tc=tb;
            tb=tb->next;
        }
        head=c->next;
    }
};