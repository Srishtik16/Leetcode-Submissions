using ll = int;
const ll MaxN = 2e5 + 5;
class SegmentTree {
public:
    vector<ll> st, lazy;
    SegmentTree(ll n) {
        st.resize(4 * MaxN, 0);
        lazy.resize(4 * MaxN, -1);
    }
    // st[node] = ans for some range
    ll merge(ll x, ll y) {
        return x + y;
    }
    void propagate(ll node, ll start, ll end) {
        if(lazy[node] == -1) {
            return;
        }
        if(start == end) {
            st[node] = lazy[node];
            lazy[node] = -1;
            return;
        }
        st[node] = (end - start + 1) * lazy[node];
        lazy[2 * node + 1] = lazy[node];
        lazy[2 * node + 2] = lazy[node];
        lazy[node] = -1;
    }
    void build(vector<ll> &a, ll node, ll start, ll end) {
        if(start == end) {
            // Leaf node
            st[node] = a[start];
            return;
        }
        // Call for left and right child
        ll mid = (start + end) / 2;
        build(a, 2 * node + 1, start, mid);
        build(a, 2 * node + 2, mid + 1, end);
        st[node] = merge(st[2 * node + 1], st[2 * node + 2]);
    }
    ll query(ll node, ll start, ll end, ll l, ll r) {
        propagate(node, start, end);
        // If [start, end] is outside [l, r]
        if(start > r || end < l) {
            return 0; // Identity element
        }
        // [l [start, end] r]
        else if(start >= l && end <= r) {
            return st[node];
        }
        ll mid = (start + end) / 2;
        ll leftAns = query(2 * node + 1, start, mid, l, r);
        ll rightAns = query(2 * node + 2, mid + 1, end, l, r);
        return merge(leftAns, rightAns);
    }
    void update(ll node, ll start, ll end, ll l, ll r, ll val) {
        propagate(node, start, end);
        // you are at that point
        if(start >= l && end <= r) {
            st[node] = (end - start + 1) * val;
            if(start != end) {
                lazy[2 * node + 1] = val;
                lazy[2 * node + 2] = val;
            }
            return;
        }
        // Completely outside
        else if(start > r || end < l) {
            return;
        }
        ll mid = (start + end) / 2;
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r , val);
        st[node] = merge(st[2 * node + 1], st[2 * node + 2]);
    }
};
class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int n = paint.size();
        SegmentTree st(n);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int start = paint[i][0];
            int end = paint[i][1];
            ans[i] = end - start - (st.query(0, 0, MaxN - 1, start + 1, end));
            st.update(0, 0, MaxN - 1, start + 1, end, 1);
        }
        return ans;
    }
};