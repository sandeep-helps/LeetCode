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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        int pos = count - n;
        if(n == count){
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }

        ListNode* temp1 = head;
        ListNode* prev = NULL;
        while(pos--){
            prev = temp1;
            temp1 = temp1->next;
        }
        prev->next = temp1->next;
        delete(temp1);
        return head;        
    }
};