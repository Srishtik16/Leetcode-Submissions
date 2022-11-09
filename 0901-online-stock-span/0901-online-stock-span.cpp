using ll = long long;
using vll = vector<long long>;
const ll MaxN = 2e5 + 5;
class SegmentTree {
public:
    vll st, lazy;
    SegmentTree() {
        st.resize(4 * MaxN, 0);
        lazy.resize(4 * MaxN, -1);
    }
    // st[node] = ans for some range
    ll merge(ll x, ll y) {
        return max(x, y);
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
        st[node] = lazy[node];
        lazy[2 * node + 1] = lazy[node];
        lazy[2 * node + 2] = lazy[node];
        lazy[node] = -1;
    }
    void build(vll &a, ll node, ll start, ll end) {
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
            st[node] = val;
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
SegmentTree st;
class StockSpanner {
public:
    int rr;
    StockSpanner() {
        st.update(0, 0, MaxN - 1, 0, MaxN - 1, 0);
        rr = 0;
    }
    int next(int price) {
        st.update(0, 0, MaxN - 1, rr, rr, price);
        int l = 0, r = rr, ans = -1;
        rr++;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(st.query(0, 0, MaxN - 1, mid, rr - 1) <= price) {
                ans = rr - mid + 1;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans == -1 ? 1 : ans - 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */