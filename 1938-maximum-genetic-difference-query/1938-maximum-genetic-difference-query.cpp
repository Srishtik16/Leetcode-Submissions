class Node {
public:
    Node* links[2];
    bool isEnd = false;
    int cnt0 = 0;
    int cnt1 = 0;
    void increase0() {
        cnt0++;
    }
    void decrease0() {
        cnt0--;
    }
    void increase1() {
        cnt1++;
    }
    void decrease1() {
        cnt1--;
    }
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
class XorTrie {
public: 
    Node* root;
    XorTrie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for(char c: word) {
            if(!node -> containsKey(c)) {
                node -> put(c, new Node());
            }
            node = node -> get(c);
            c == '0' ? (node -> increase0()) : (node -> increase1());
        }
        node -> setEnding();
    }
    void remove(string word) {
        Node* node = root;
        for(char c: word) {
            node = node -> get(c);
            c == '0' ? (node -> decrease0()) : (node -> decrease1());
        }
    }
    int getBestXor(string word) {
        Node* node = root;
        int ans = 0;
        int pw = 31;
        for(char c: word) {
            char fc = (c == '0' ? '1' : '0');
            if(node -> containsKey(fc)) {
                Node* temp = node;
                temp = temp -> get(fc);
                if(fc == '0' ? (temp -> cnt0 > 0) : (temp -> cnt1 > 0)) {
                    node = node -> get(fc);
                    ans += (1 << pw);
                }
                else {
                    node = node -> get(c);
                }
            }
            else {
                node = node -> get(c);
            }
            pw--;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    map<int, vector<pair<int, int>>> mapped;
    vector<int> ans;
    XorTrie* trie;
    string toBinary(int x) {
        string s = "";
        while(x > 0) {
            s += (x % 2 ? '1' : '0');
            x /= 2;
        }
        while(s.size() < 32) {
            s += '0';
        }
        reverse(s.begin(), s.end());
        return s;
    }
    void dfs(int node) {
        vis[node] = true;
        trie -> insert(toBinary(node));
        for(auto x: mapped[node]) {
            ans[x.second] = trie -> getBestXor(toBinary(x.first));
        }
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x);
            }
        }
        trie -> remove(toBinary(node));
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        trie = new XorTrie();
        int q = queries.size();
        mapped.clear();
        for(int i = 0; i < q; i++) {
            mapped[queries[i][0]].push_back({queries[i][1], i});
        }
        int n = parents.size();
        adj = vector<vector<int>>(n);
        int root = 0;
        for(int i = 0; i < n; i++) {
            if(parents[i] == -1) {
                root = i;
                continue;
            }
            adj[parents[i]].push_back(i);
            adj[i].push_back(parents[i]);
        }
        vis = vector<bool>(n);
        ans = vector<int>(q);
        dfs(root);
        return ans;
    }
};