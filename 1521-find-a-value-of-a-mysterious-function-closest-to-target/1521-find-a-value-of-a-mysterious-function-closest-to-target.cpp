using ll = int;
const ll MaxN = 1e5 + 5;
vector<ll> st(4 * MaxN, (1LL << 30) - 1);
ll merge(ll x, ll y) {
    return x & y;
}
void build(ll node, ll start, ll end, vector<ll> &a) {
    if(start == end) {
        st[node] = a[start];
        return;
    }
    ll mid = (start + end) / 2;
    build(2 * node + 1, start, mid, a);
    build(2 * node + 2, mid + 1, end, a);
    st[node] = merge(st[2 * node + 1], st[2 * node + 2]);
}
ll query(ll node, ll start, ll end, ll l, ll r) {
    // [l, r] [start end] [l r]
    if(start > r || end < l) {
        return (1LL << 30) - 1;
    }
    // [l start end r]
    if(start >= l && end <= r) {
        return st[node];
    }
    ll mid = (start + end) / 2;
    ll leftAns = query(2 * node + 1, start, mid, l, r);
    ll rightAns = query(2 * node + 2, mid + 1, end, l, r);
    return merge(rightAns, leftAns);
}
class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();
        build(0, 0, n - 1, arr);
        int res = INT_MAX;
        for(int i = 0; i < n; i++) {
            int l = i, r = n - 1, ans = i;
            while(l <= r) {
                int mid = (l + r) / 2;
                int qry = query(0, 0, n - 1, i, mid);
                if(qry >= target) {
                    ans = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            for(int k = ans - 3; k <= ans + 3; k++) {
                int qry = query(0, 0, n - 1, i, k);
                res = min(res, abs(target - qry));
            }
        }
        return res;
    }
};