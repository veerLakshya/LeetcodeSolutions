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
        if(!head || !head->next || !head->next->next) return {-1,-1};
        ListNode* curr = head->next;
        int prev = head->val;
        while(curr->next!=NULL){
            int x = curr->val;
            int next = curr->next->val;
            if((x>next && x>prev) || (x<next && x<prev))break;
            else{
                prev = x;
            }
            curr = curr->next;
        }
        if(curr == NULL ||curr->next == NULL)return {-1,-1};
        prev = curr->val;
        curr = curr->next;
        int mini = INT_MAX, ind = 0, last = 0;
        while(curr->next!=NULL){
            ind++;
            int x = curr->val;
            int next = curr->next->val;
            if((x>next && x>prev) || (x<next && x<prev)){
                mini= min(mini, ind - last);
                last = ind;
            }
            prev = x;
            curr = curr->next;
        }
        return {mini!=INT_MAX?mini:-1 , last!=0?last:-1}; 
    }
};