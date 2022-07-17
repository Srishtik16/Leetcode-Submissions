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
    ListNode* reverse(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head -> next;
        while(curr != NULL) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(next != NULL) {
                next = next -> next;
            }
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL) {
            if(fast -> next -> next != NULL) {
                fast = fast -> next -> next;
                slow = slow -> next;
            }
            else {
                fast = fast -> next;
            }
        }
        slow -> next = reverse(slow -> next);
        slow = slow -> next;
        while(slow != NULL) {
            if(head -> val != slow -> val) {
                return false;
            }
            head = head -> next;
            slow = slow -> next;
        }
        return true;
    }
};