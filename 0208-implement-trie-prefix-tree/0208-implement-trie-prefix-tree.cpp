class Node {
public:
    Node* links[26];
    bool isEnding;
    bool containsKey(char c) {
        return links[c - 'a'] != NULL;
    }
    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }
    Node* get(char c) {
        return links[c - 'a'];
    }
    void setEnd() {
        isEnding = true;
    }
    bool isEnd() {
        return isEnding;
    }
};
class Trie {
    Node* root;
public:
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
        node -> setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(char c: word) {
            if(!node -> containsKey(c)) {
                return false;
            }
            node = node -> get(c);
        }
        return node -> isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char c: prefix) {
            if(!node -> containsKey(c)) {
                return false;
            }
            node = node -> get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */