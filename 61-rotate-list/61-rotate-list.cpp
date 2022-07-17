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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        int n = 0;
        ListNode* aux = head;
        while(aux != NULL) {
            n++;
            aux = aux -> next;
        }
        aux = head;
        while(aux -> next != NULL) {
            aux = aux -> next;
        }
        aux -> next = head;
        k %= n;
        k = n - k;
        ListNode* start = head;
        while(k-- > 1) {
            start = start -> next;
        }
        head = start -> next;
        start -> next = NULL;
        return head;
    }
};