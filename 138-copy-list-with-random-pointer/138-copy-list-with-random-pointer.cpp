/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = head;
        while(dummy != NULL) {
            Node* front = dummy -> next;
            Node* copy = new Node(dummy -> val);
            dummy -> next = copy;
            copy -> next = front;
            dummy = front;
        }
        dummy = head;
        while(dummy != NULL) {
            if(dummy -> random != NULL) {
                dummy -> next -> random = dummy -> random -> next;
            }
            dummy = dummy -> next -> next;
        }
        dummy = head;
        Node* fakeHead = new Node(0);
        Node* copy = fakeHead;
        while(dummy != NULL) {
            Node* front = dummy -> next -> next;
            copy -> next = dummy -> next;
            dummy -> next = front;
            copy = copy -> next;
            dummy = front;
        }
        return fakeHead -> next;
    }
};