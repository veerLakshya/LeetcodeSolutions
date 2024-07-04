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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prevZero = head;
        int sum = 0;
        while(curr != nullptr){
            if(curr->val == 0){
                prevZero->val = sum;
                prevZero->next = curr;
                prevZero = curr;
                sum = 0;
                // if(curr->next == nullptr){
                // }
            }
            sum += curr->val;
            curr = curr->next;
        }
        curr = head;
        while(curr->next->val !=0){
            curr = curr->next;
        }
        curr->next = nullptr;
        return head;   
    }
};