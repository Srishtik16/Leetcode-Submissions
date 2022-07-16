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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ha = headA;
        ListNode* hb = headB;
        while(ha != hb) {
            if(ha == NULL) {
                ha = headB;
            }
            else {
                ha = ha -> next;
            }
            if(hb == NULL) {
                hb = headA;
            }
            else {
                hb = hb -> next;
            }
        }
        return ha;
    }
};