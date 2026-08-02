/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getListLength(ListNode *head){
        int length = 0;
        while(head != NULL){
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = getListLength(headA);
        int lenb = getListLength(headB);

        while(lena > lenb){
            lena--;
            headA = headA->next;
        }
        while(lenb > lena){
            lenb--;
            headB = headB->next;
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};