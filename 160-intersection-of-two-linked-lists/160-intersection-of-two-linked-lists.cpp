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
        // Keep 2 pointers at head of the 2 lists
        // Move them forward by 1
        // If any pointer reaches end of list. start it from head of other list
        // Loop continues till both pointer points to same node which will be our intersection node
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