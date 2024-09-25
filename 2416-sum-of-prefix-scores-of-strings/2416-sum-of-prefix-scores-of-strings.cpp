class Node {
public:
    Node* links[26];
    bool isEnd = false;
    int cnts = 0;
    bool containsKey(char c) {
        return links[c - 'a'] != NULL;
    }
    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }
    Node* get(char c) {
        return links[c - 'a'];
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
    void insert(string &word) {
        Node* node = root;
        for(char c: word) {
            if(!node -> containsKey(c)) {
                node -> put(c, new Node());
            }
            node = node -> get(c);
            node -> cnts++;
        }
        node -> setEnding();
    }
    int countPrefixes(string &word) {
        Node* node = root;
        int count = 0;
        for(char c: word) {
            if(!node -> containsKey(c)) {
                return count;
            }
            node = node -> get(c);
            count += node -> cnts;
        }
        return count;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for(auto x: words) {
            trie -> insert(x);
        }
        vector<int> ans;
        for(auto x: words) {
            ans.push_back(trie -> countPrefixes(x));
        }
        return ans;
    }
};