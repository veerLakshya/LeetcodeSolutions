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
        ListNode* dummy = new ListNode;
        ListNode* temp = dummy;
        int sum = 0;
        ListNode* curr = head->next;
        while(curr!=NULL){
            if(curr->val == 0){
                ListNode* newnode = new ListNode(sum);
                temp->next = newnode;
                sum=0;
                temp = temp->next;
            }
            sum += curr->val;
            curr = curr->next;
        }
        return dummy->next;
    }
};