struct Node {
    Node* links[27]; // Links which form the trie
    bool isEnd = false; // Checks if this is end of current word
    // Checks if current key is present in the TrieNode
    bool containsKey(char c) {
        return links[c - 'a'] != NULL;
    }
    // Inserts key in the current TrieNode
    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }
    // Gets Node pointed to by current link
    Node* get(char c) {
        return links[c - 'a'];
    }
    // Decides the end of a word
    void setEnd() {
        isEnd = true;
    }
    // Checks if a word has ended or not
    bool isEnding() {
        return isEnd;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        // Creates new trienode
        root = new Node();
    }
    // TC: O(length of word)
    void insert(string word) {
        // Dummy node pointing to root.
        Node* node = root;
        for(char c: word) {
            // If key is not present in Trie, insert that key into the trie node.
            if(!node -> containsKey(c)) {
                node -> put(c, new Node());
            }
            // Moves to the reference Trie
            node = node -> get(c);
        }
        // Mark end of current word
        node -> setEnd();
    }
    // TC: O(length of word)
    bool search(string word) {
        Node* node = root;
        for(char c: word) {
            // If key is not present, word doesnt exist
            if(!node -> containsKey(c)) {
                return false;
            }
            // Go to next link address
            node = node -> get(c);
        }
        // Check if word has ended
        return node -> isEnding();
    }
    void dfs(Node* node, vector<string> &words, string &word) {
        if(words.size() == 3) {
            return;
        }
        Node* curr = node;
        if(curr -> isEnding()) {
            words.push_back(word);
        }
        for(char c = 'a'; c <= 'z'; c++) {
            if(curr -> containsKey(c)) {
                word += c;
                dfs(curr -> get(c), words, word);
                word.pop_back();
            }
        }
    }
    // TC: O(length of word)
    vector<string> startsWith(string prefix) {
        Node* node = root;
        vector<string> words;
        for(char c: prefix) {
            // If key is not present, word doesn't exist
            if(!node -> containsKey(c)) {
                return words;
            }
            // Go to next link address
            node = node -> get(c);
        }
        dfs(node, words, prefix);
        return words;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for(auto x: products) {
            trie -> insert(x);
        }
        string prefix = "";
        vector<vector<string>> ans;
        for(char c: searchWord) {
            prefix += c;
            ans.push_back(trie -> startsWith(prefix));
        }
        return ans;
    }
};