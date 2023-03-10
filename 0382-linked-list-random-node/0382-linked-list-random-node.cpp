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
    ListNode* node;
    int len;
    Solution(ListNode* head) {
        node = head;
        len = 0;
        while(head != NULL) {
            head = head -> next;
            len++;
        }
    }
    
    int getRandom() {
        ListNode* curr = node;
        int i = rand() % len;
        while(i--) {
            curr = curr -> next;
        }
        return curr -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */