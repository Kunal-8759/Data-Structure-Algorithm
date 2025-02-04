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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* middle=findMiddle(head);
        ListNode* newHead=reverse(middle);

        while(head!=NULL && newHead!=NULL){
            if(head->val!=newHead->val) return false;
            head=head->next;
            newHead=newHead->next;
        }
        return true;
    }
};