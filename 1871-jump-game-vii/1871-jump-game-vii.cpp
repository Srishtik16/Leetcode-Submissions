class SegmentTree {
    public:
    vector<int> st;
    SegmentTree(int n) {
        st.clear();
        st.resize(4 * n);
    }
    int merge(int x, int y) {
        return x + y;
    }
    
    void update(int node, int pos, int val, int start, int end) {
        if(start > pos || end < pos || start > end) {
            return;
        }
        if(start == end && end == pos) {
            st[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node + 1, pos, val, start, mid);
        update(2 * node + 2, pos, val, mid + 1, end);
        st[node] = merge(st[2 * node + 1], st[2 * node + 2]);
    }
    
    int query(int node, int start, int end, int l, int r) {
        if(l > end || r < start) {
            return 0;
        }
        if(l <= start && end <= r) {
            return st[node];
        }
        int mid = (start + end) / 2;
        return merge(query(2 * node + 1, start, mid, l, r), query(2 * node + 2, mid + 1, end, l, r));
    }
};
class Solution {
public:
    
    bool canReach(string s, int minJump, int maxJump) {
        // dp[i] = is index i reachable?
        // dp[0] = true, dp[s[i] == 1] = false
        // dp[i] = sum of dp[j] from i - minJump <= j <= i - maxJump > 0, use segmemt tree
        // ans = dp.back()
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        SegmentTree st(n + 1);
        st.update(0, 0, 1, 0, n);
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                int l = i - maxJump;
                int r = i - minJump;
                dp[i] = st.query(0, 0, n, l, r) > 0;
                st.update(0, i, dp[i], 0, n);
            }
        }
        return dp.back();
    }
};