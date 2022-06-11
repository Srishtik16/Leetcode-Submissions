struct Node {
    Node* links[2]; // Links which form the trie
    bool isEnd = false; // Checks if this is end of current word
    // Checks if current key is present in the TrieNode
    bool containsKey(char c) {
        return links[c - '0'] != NULL;
    }
    // Inserts key in the current TrieNode
    void put(char c, Node* node) {
        links[c - '0'] = node;
    }
    // Gets Node pointed to by current link
    Node* get(char c) {
        return links[c - '0'];
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
    string getMax(string s) {
        Node* node = root;
        string ans = "";
        for(char c: s) {
            char invc = c == '1' ? '0' : '1';
            if(node -> containsKey(invc)) {
                ans += '1';
                node = node -> get(invc);
            }
            else {
                ans += '0';
                node = node -> get(c);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
       vector<vector<int>> qry;
        int q = queries.size();
        for(int i = 0; i < q; i++) {
            vector<int> qr = {queries[i][0], queries[i][1], i};
            qry.push_back(qr);
        }
        vector<int> ans(q);
        sort(qry.begin(), qry.end(), [&](const auto &x, const auto &y) {
            return x[1] < y[1]; 
        });
        auto toBinary = [&](int x) {
            string ans = "";
            for(int i = 0; i < 32; i++) {
                ans += (x % 2 == 0 ? '0' : '1');
                x /= 2;
            }
            reverse(ans.begin(), ans.end());
            return ans;
        };
        auto toDecimal = [&](string s) {
            reverse(s.begin(), s.end());
            int ans = 0, bit = 0;
            for(char c: s) {
                ans += (1LL << bit) * (c == '0' ? 0 : 1);
                bit++;
            }
            return ans;
        };
        Trie* trie = new Trie();
        int ptr = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(auto x: qry) {
            if(nums[0] > x[1]) {
                ans[x[2]] = -1;
                continue;
            }
            while(ptr < n && nums[ptr] <= x[1]) {
                trie -> insert(toBinary(nums[ptr]));
                ptr++;
            }
            int res = toDecimal(trie -> getMax(toBinary(x[0])));
            ans[x[2]] = res;
        }
        return ans;
    }
};