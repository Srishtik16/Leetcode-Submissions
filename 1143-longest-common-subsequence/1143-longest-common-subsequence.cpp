class SegmentTree {
public:
    vector<int> st;
    int n;
    SegmentTree(int _n) {
        n = _n;
        st.assign(4 * n, 0);
    }
    int merge(int x, int y) {
        return max(x, y);
    }
    void build(int node, int start, int end, vector<int> &a) {
        if(start == end) {
            st[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, a);
        build(2 * node + 2, mid + 1, end, a);
        st[node] = merge(st[2 * node + 1], st[2 * node + 2]);
    }
    int query(int node, int start, int end, int l, int r) {
        if(start >= l && end <= r) {
            return st[node];
        }
        if(start > r || end < l) {
            return INT_MIN;
        }
        int mid = (start + end) / 2;
        return merge(query(2 * node + 1, start, mid, l, r), query(2 * node + 2, mid + 1, end, l, r));
    }
    void update(int node, int start, int end, int index, int val) {
        if(start == end && start == index) {
            st[node] = val;
            return;
        }
        if(end < index || start > index) {
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, index, val);
        update(2 * node + 2, mid + 1, end, index, val);
        st[node] = merge(st[2 * node + 1], st[2 * node + 2]);
    }
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    void update(int index, int val) {
        update(0, 0, n - 1, index, val);
    }
};
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        map<char, vector<int>> adj;
        for(int i = 0; i < m; i++) {
            adj[t[i]].push_back(i);
        }
        for(auto &x: adj) {
            sort(x.second.rbegin(), x.second.rend());
        }
        vector<int> nums;
        for(char c: s) {
            for(auto x: adj[c]) {
                nums.push_back(x + 1);
            }
        }
        if(nums.empty()) {
            return 0;
        }
        int mx = *max_element(nums.begin(), nums.end());
        SegmentTree st(mx + 1);
        int ans = 1;
        n = nums.size();
        for(int i = 0; i < n; i++) {
            int l = 0;
            int r = nums[i] - 1;
            ans = max(ans, st.query(l, r) + 1);
            st.update(nums[i], st.query(l, r) + 1);
        }
        return ans;
    }
};