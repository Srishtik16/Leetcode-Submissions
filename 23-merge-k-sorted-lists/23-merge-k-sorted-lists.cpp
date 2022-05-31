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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        else if(l2 == NULL) {
            return l1;
        }
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
        while(l1 != NULL && l2 != NULL) {
            if(l1 -> val < l2 -> val) {
                node -> next = l1;
                l1 = l1 -> next;
            }
            else {
                node -> next = l2;
                l2 = l2 -> next;
            }
            node = node -> next;
        }
        if(l1 != NULL) {
            node -> next = l1;
        }
        if(l2 != NULL) {
            node -> next = l2;
        }
        node = dummy -> next;
        return node;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) {
            return NULL;
        }
        int del = 1;
        while(n - del > 0) {
            for(int i = 0; i < n - del; i += del * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + del]);
            }
            del *= 2;
        }
        return lists[0];
    }
};