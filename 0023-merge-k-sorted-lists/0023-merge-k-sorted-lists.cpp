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
    //marge k sortd
    ListNode* margeTwoList(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val){
            l1->next = margeTwoList(l1->next, l2);
            return l1;
        }
        else{
            l2->next = margeTwoList(l1, l2->next);
            return l2;
        }
        return margeTwoList(l1, l2);
    }
    ListNode* partitionMarge(int start, int end, vector<ListNode*>lists){
        if(start>end){
            return NULL;
        }
        if(start == end){
            return lists[start];
        }
        int mid = start+(end-start)/2;
        ListNode* l1 = partitionMarge(start, mid, lists);
        ListNode* l2 = partitionMarge(mid+1, end, lists);
        return margeTwoList(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0){
            return NULL;
        }
        return partitionMarge(0, k-1, lists);
    }
};