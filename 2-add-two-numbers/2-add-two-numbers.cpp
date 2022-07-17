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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* aux = new ListNode(0);
        ListNode* curr = aux;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0) {
            int sum = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + carry;
            carry = sum / 10;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            l1 = l1 ? l1 -> next : NULL;
            l2 = l2 ? l2 -> next : NULL;
        }
        return aux -> next;
    }
};