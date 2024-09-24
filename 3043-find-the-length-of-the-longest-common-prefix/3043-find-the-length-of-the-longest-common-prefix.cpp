class Node {
public:
    Node* links[10];
    bool isEnd = false;
    bool containsKey(char c) {
        return links[c - '0'] != NULL;
    }
    void put(char c, Node* node) {
        links[c - '0'] = node;
    }
    Node* get(char c) {
        return links[c - '0'];
    }
    void setEnding() {
        isEnd = true;
    }
    bool isEnding() {
        return isEnd;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for(char c: word) {
            if(!node -> containsKey(c)) {
                node -> put(c, new Node());
            }
            node = node -> get(c);
        }
        node -> setEnding();
    }
    int getMaxPrefix(string prefix) {
        int cnt = 0;
        Node* node = root;
        for(char c: prefix) {
            if(!node -> containsKey(c)) {
                return cnt;
            }
            node = node -> get(c);
            cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* trie = new Trie();
        for(auto x: arr1) {
            trie -> insert(to_string(x));
        }
        int ans = 0;
        for(auto x: arr2) {
            ans = max(ans, trie -> getMaxPrefix(to_string(x)));
        }
        return ans;
    }
};