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
ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next == NULL)
        return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp=front;
        }
        return prev;

    }
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        ListNode* temp= head;
        int carry=0;
        while(temp!=NULL){
            int data = temp->val;
            data*=2;
            data+=carry;
            carry=0;
            if(data>9){
                data%=10;
                carry=1;
            }
            temp->val = data;
            if(temp->next!=NULL)temp=temp->next;
            else break;
        }
        if(carry==1){
            ListNode* newNode = new ListNode(1);
            temp->next= newNode;
            temp=temp->next;
        }
        head = reverseList(head);
        return head;
    }
};