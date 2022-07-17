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
        ListNode* h1 = head;
        ListNode* h2 = head;
        if(n == 1) {
            if(h1 == NULL || h1 -> next == NULL) {
                return NULL;
            }
            while(h1 -> next -> next != NULL) {
                h1 = h1 -> next;
            }
            h1 -> next = h1 -> next -> next;
            return head;
        }
        for(int i = 0; i < n; i++) {
            h1 = h1 -> next;
        }
        while(h1 != NULL) {
            h1 = h1 -> next;
            h2 = h2 -> next;
        }
        h2 -> val = h2 -> next -> val;
        h2 -> next = h2 -> next -> next;
        return head;
    }
};