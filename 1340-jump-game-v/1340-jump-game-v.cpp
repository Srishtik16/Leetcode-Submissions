class SegmentTree {
    public:
    vector<int> st;
    SegmentTree(int n) {
        st.clear();
        st.assign(4 * n, -1);
    }
    int merge(int x, int y) {
        return max(x, y);
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
        if(l > end || r < start || l > r) {
            return -1;
        }
        if(l <= start && end <= r) {
            return st[node];
        }
        int mid = (start + end) / 2;
        return merge(query(2 * node + 1, start, mid, l, r), query(2 * node + 2, mid + 1, end, l, r));
    }
};

// For every i, finds the largest j < i such that `compare(values[j], values[i])` is true, or -1 if no such j exists.
template<typename T, typename T_compare>
vector<int> closest_left(const vector<T> &values, T_compare &&compare) {
    int n = int(values.size());
    vector<int> closest(n);
    vector<int> stack;

    for (int i = 0; i < n; i++) {
        while (!stack.empty() && !compare(values[stack.back()], values[i]))
            stack.pop_back();

        closest[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }

    return closest;
}

// For every i, finds the smallest j > i such that `compare(values[j], values[i])` is true, or `n` if no such j exists.
template<typename T, typename T_compare>
vector<int> closest_right(const vector<T> &values, T_compare &&compare) {
    int n = int(values.size());
    vector<int> closest(n);
    vector<int> stack;

    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && !compare(values[stack.back()], values[i]))
            stack.pop_back();

        closest[i] = stack.empty() ? n : stack.back();
        stack.push_back(i);
    }

    return closest;
}

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> left = closest_left(arr, greater_equal<int>());
        vector<int> right = closest_right(arr, greater_equal<int>());
        SegmentTree st(n + 1);
        vector<int> dp(n);
        // Process in order of smallest element first
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int &x, const int &y) {
            return arr[x] < arr[y];
        });
        for(int i = 0; i < n; i++) {
            int l = max(order[i] - d - 1, left[order[i]]);
            int r = min(order[i] + d + 1, right[order[i]]);
            int ql = st.query(0, 0, n - 1, l + 1, order[i] - 1);
            int qr = st.query(0, 0, n - 1, order[i] + 1, r - 1);
            int bestq = 0;
            if(ql > -1) {
                bestq = ql;
            }
            if(qr > -1) {
                bestq = max(bestq, qr);
            }
            dp[order[i]] = 1 + bestq;
            st.update(0, order[i], dp[order[i]], 0, n - 1);
        }
        return *max_element(dp.begin(), dp.end());
    }
};