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
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[i] = length of LIS ending at value i
        // dp[i] = max(dp[i - k] .... dp[i - 1]) + 1
        // dp[0] = -INF
        int mx = *max_element(nums.begin(), nums.end());
        SegmentTree st(mx + 1);
        int ans = 1;
        for(int i = 0; i < n; i++) {
            int l = max(0, nums[i] - k);
            int r = nums[i] - 1;
            ans = max(ans, st.query(l, r) + 1);
            st.update(nums[i], st.query(l, r) + 1);
        }
        return ans;
    }
};