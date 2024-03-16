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
    ListNode* getKthNode(ListNode* temp, int  k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;
        
        while(temp!=NULL)
        {
            ListNode* kThNode = getKthNode(temp,k);
            if(kThNode == NULL){
                if(prevlast) prevlast->next = temp;
                break;
            }
            ListNode* nextNode = kThNode->next;
            kThNode->next =NULL;
            reverseList(temp);
            if(temp==head)head = kThNode;
            else prevlast->next = kThNode;
            prevlast =temp;
            temp =nextNode;
        }
        return head;

    }
};