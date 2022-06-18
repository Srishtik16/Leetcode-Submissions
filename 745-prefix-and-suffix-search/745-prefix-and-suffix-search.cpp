struct Node {
    Node* links[27]; // Links which form the trie
    bool isEnd = false; // Checks if this is end of current word
    int index = -1;
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
    void insert(string word, int index) {
        // Dummy node pointing to root.
        Node* node = root;
        for(char c: word) {
            // If key is not present in Trie, insert that key into the trie node.
            if(!node -> containsKey(c)) {
                node -> put(c, new Node());
            }
            // Moves to the reference Trie
            node = node -> get(c);
            node -> index = index;
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
    int prefixSuffixSearch(string word) {
        Node* node = root;
        for(char c: word) {
            if(!node -> containsKey(c)) {
                return -1;
            }
            node = node -> get(c);
        }
        return node -> index;
    }
};
class WordFilter {
public:
    Trie* trie;
    WordFilter(vector<string>& words) {
        trie = new Trie();
        int ind = 0;
        for(auto x: words) {
            int n = x.size();
            string suff = "";
            for(int i = n - 1; i >= 0; i--) {
                suff += x[i];
                string suffRev = suff;
                reverse(suffRev.begin(), suffRev.end());
                string newWord = suffRev + "{" + x;
                trie -> insert(newWord, ind);
            }
            ind++;
        }
    }
    
    int f(string prefix, string suffix) {
        string word = suffix + "{" + prefix;
        return trie -> prefixSuffixSearch(word);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */