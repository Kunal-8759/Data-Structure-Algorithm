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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prevSlow=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }

        while(fast!=NULL){
            prevSlow=slow;
            slow=slow->next;
            fast=fast->next;
        }

        if(head==slow) return head->next;//ensuring size==n

        prevSlow->next=slow->next;
        delete(slow);
        return head;

    }
};