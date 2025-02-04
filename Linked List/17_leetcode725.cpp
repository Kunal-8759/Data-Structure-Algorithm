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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //find the length   
        ListNode* temp=head;
        int L=0;
        while(temp!=NULL){
            L++;
            temp=temp->next;
        }
        temp=head;

        int extraNodes=L%k;
        ListNode* prev=NULL;
        vector<ListNode*> v;//vector of size k and default value is NULL

        while(temp!=NULL){
            ListNode* ptr=temp;
            for(int i=1;i<=L/k +(extraNodes>0 ? 1:0);i++){
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            extraNodes--;

            v.push_back(ptr);

        }
        while(k-v.size()){
            v.push_back(NULL);
        }
        return v;
    }
};