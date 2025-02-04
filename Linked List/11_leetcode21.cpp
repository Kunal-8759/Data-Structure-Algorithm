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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* c=new ListNode(-1);
        ListNode* tempc=c;

        ListNode* temp1=list1;
        ListNode* temp2=list2;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                tempc->next=temp1;
                tempc=temp1;
                temp1=temp1->next;
            }
            else{
                tempc->next=temp2;
                tempc=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1!=NULL) tempc->next=temp1;
        if(temp2!=NULL) tempc->next=temp2;

        return c->next;
    }
};