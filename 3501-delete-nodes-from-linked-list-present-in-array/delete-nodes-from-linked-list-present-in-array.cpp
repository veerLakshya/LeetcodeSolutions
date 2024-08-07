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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(auto i: nums)st.insert(i);
        ListNode* dummy = new ListNode(-1,head);
        ListNode* temp = dummy;
        while(temp->next!=nullptr){
            if(st.find(temp->next->val)!=st.end()){
                temp->next = temp->next->next;
            }
            else{
                temp = temp -> next;
            }
        }
        return dummy->next;
    }
};