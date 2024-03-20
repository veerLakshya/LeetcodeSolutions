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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;
        int cnt=0;
        while(temp!=NULL)
        {
            if(cnt==a-1)
            temp1 = temp;
            if(cnt==b+1)
            temp2 = temp;
            cnt++;
            temp=temp->next;

        }
        temp=list2;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp1->next=list2;
        temp->next = temp2;
        return list1;
    }
};