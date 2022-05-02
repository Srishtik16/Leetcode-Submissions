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
        ListNode* prev = NULL;
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* curr = head -> next;
        while(head != NULL) {
            head -> next = prev;
            prev = head;
            head = curr;
            if(curr != NULL) {
                curr = curr -> next;
            }
        }
        return prev;
    }
};