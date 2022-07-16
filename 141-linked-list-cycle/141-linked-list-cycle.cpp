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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(true) {
            if(fast != NULL && fast -> next != NULL && fast -> next -> next != NULL) {
                fast = fast -> next -> next;
                slow = slow -> next;
            }
            else {
                return false;
            }
            if(fast == slow) {
                return true;
            }
        }
    }
};