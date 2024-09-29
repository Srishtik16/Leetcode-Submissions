class SegmentTree {
public:
    vector<int> st;
    SegmentTree(int n) {
        st.resize(4 * n);
    }
    int merge(int x, int y) {
        return x | y;
    }
    int query(int node, int start, int end, int l, int r) {
        // start end l r
        if(end < l || r < start) {
            return 0;
        }
        // l start end r
        if(l <= start && end <= r) {
            return st[node];
        }
        int mid = (start + end) / 2;
        return merge(query(2 * node + 1, start, mid, l, r), query(2 * node + 2, mid + 1, end, l, r));
    }
    void update(int node, int start, int end, int idx, int val) {
        if(end < idx || idx < start) {
            return;
        }
        if(start == end && end == idx) {
            st[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, idx, val);
        update(2 * node + 2, mid + 1, end, idx, val);
        st[node] = merge(st[2 * node + 1], st[2 * node + 2]);
    }
};
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree st(n + 1);
        int best = INT_MAX;
        for(int i = 0; i < n; i++) {
            int l = 0, r = i, ans = -1;
            st.update(0, 0, n - 1, i, nums[i]);
            while(l <= r) {
                int mid = (l + r) / 2;
                int q = st.query(0, 0, n - 1, mid, i);
                if(q == k) {
                    ans = q;
                    break;
                }
                else if(q <= k) {
                    ans = q;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            if(ans != -1) {
                best = min(best, abs(ans - k));
            }
            l = 0, r = i, ans = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                int q = st.query(0, 0, n - 1, mid, i);
                if(q > k) {
                    ans = q;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            if(ans != -1) {
                best = min(best, abs(ans - k));
            }
        }
        return best;
    }
};