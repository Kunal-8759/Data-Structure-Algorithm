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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;

        vector<int> v(2,-1);

        if(head->next==NULL || head->next->next==NULL) return v;

        int minDistance=INT_MAX;
        int maxDistance=INT_MIN;

        int currCritical=1;
        int prevCritical=0;//no prev critical point;
        int firstCritical=-1;
        while(curr->next!=NULL){
            if(curr->val < curr->next->val && curr->val < prev->val  || curr->val > curr->next->val && curr->val > prev->val){
                //check it is first critical point or not
                if(prevCritical==0){//it is first critical
                    firstCritical=currCritical;
                    prevCritical=currCritical;
                }
                else{
                    minDistance=min(minDistance,currCritical-prevCritical);
                    prevCritical=currCritical;
                }
            }
            currCritical++;
            prev=curr;
            curr=curr->next;
        }
        if(firstCritical==-1 || prevCritical==firstCritical){//no critical point or only one critical point
            return v;
        }
        v[0]=minDistance;
        v[1]=prevCritical-firstCritical;
        return v;
    }
};