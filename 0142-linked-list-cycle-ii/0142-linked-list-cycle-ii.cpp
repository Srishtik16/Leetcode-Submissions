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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* entry = head;
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(slow == fast) {
                break;
            }
        }
        if(slow != fast) {
            return NULL;
        }
        while(entry != slow) {
            slow = slow -> next;
            entry = entry -> next;
        }
        return entry;
    }
};