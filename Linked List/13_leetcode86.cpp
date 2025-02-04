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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* low=new ListNode(-1);
        ListNode* high=new ListNode(-1);
        ListNode* tl=low;
        ListNode* th=high;

        ListNode* temp=head;

        while(temp!=NULL){
            if(temp->val < x){
                tl->next=temp;
                tl=temp;
                temp=temp->next;
            }
            else{
                th->next=temp;
                th=temp;
                temp=temp->next;
            }
        }
        tl->next=NULL;
        th->next=NULL;

        tl->next=high->next;
        return low->next;

    }
};  