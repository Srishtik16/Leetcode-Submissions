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
        ListNode* fast = head;
        ListNode* slow = head;
        if(head == NULL || head -> next == NULL) {
            return false;
        }
        while(fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == NULL) {
                break;
            }
            if(fast == slow) {
                return true;
            }
        }
        return false;
    }
};

// T = 3, H = 3
// T = 2, H = 0
// T = 0, H = 2
// T = -4, H = -4