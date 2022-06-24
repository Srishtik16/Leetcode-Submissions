struct Node {
    Node* links[26]; // Links which form the trie
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
    Trie(Node* node) {
        // Creates new trienode
        root = node;
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
    bool search(Node* node, string &word) {
        int i = 0;
        for(char c: word) {
            // If key is not present, word doesnt exist
            if(c == '.') {
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    if(node -> containsKey(ch)) {
                        string w = word.substr(i + 1);
                        if(search(node -> get(ch), w)) {
                            return true;
                        }
                    }
                }
                return false;
            }
            if(!node -> containsKey(c)) {
                return false;
            }
            // Go to next link address
            node = node -> get(c);
            i++;
        }
        // Check if word has ended
        return node -> isEnding();
    }
    // TC: O(length of word)
    bool startsWith(string prefix) {
        Node* node = root;
        for(char c: prefix) {
            // If key is not present, word doesn't exist
            if(!node -> containsKey(c)) {
                return false;
            }
            // Go to next link address
            node = node -> get(c);
        }
        return true;
    }
};
class WordDictionary {
public:
    Trie* trie;
    Node* root;
    WordDictionary() {
        root = new Node();
        trie = new Trie(root);
    }
    
    void addWord(string word) {
        trie -> insert(word);
    }
    
    bool search(string word) {
        return trie -> search(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */