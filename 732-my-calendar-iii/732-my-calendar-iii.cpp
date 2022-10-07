using ll = long long;
const ll MaxN = 1e9 + 5;
class SegmentTree {
public:
    unordered_map<ll, ll> st, lazy;
    SegmentTree() {
        st.clear();
        lazy.clear();
    }
    // st[node] = ans for some range
    ll merge(ll x, ll y) {
        return max(x, y);
    }
    void propagate(ll node, ll start, ll end) {
        if(lazy[node] == 0) {
            return;
        }
        if(start == end) {
            st[node] += lazy[node];
            lazy[node] = 0;
            return;
        }
        st[node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
        lazy[node] = 0;
    }
    void build(vector<int> &a, ll node, ll start, ll end) {
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
            return LLONG_MAX; // Identity element
        }
        // [l [start, end] r]
        else if(start >= l && end <= r) {
            return st[node];
        }
        ll mid = (start + end) / 2;
        ll leftAns = query(2 * node + 1, start, mid, l, r);
        ll rightAns = query(2 * node + 2, mid + 1, end, l, r);
        return min(leftAns, rightAns);
    }
    void update(ll node, ll start, ll end, ll l, ll r, ll val) {
        propagate(node, start, end);
        // you are at that point
        if(start >= l && end <= r) {
            st[node] += val;
            if(start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
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
class MyCalendarThree {
public:
    SegmentTree st;
    MyCalendarThree() {
        ;
    }
    
    int book(int start, int end) {
        st.update(0, 0, MaxN - 1, start, end - 1, 1);
        return st.query(0, 0, MaxN - 1, 0, MaxN - 1);
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */