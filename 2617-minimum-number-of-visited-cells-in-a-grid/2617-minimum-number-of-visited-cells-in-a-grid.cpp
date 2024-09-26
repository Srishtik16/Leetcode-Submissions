class SegmentTree {
public:
    vector<int> st;
    SegmentTree(int n) {
        st.assign(4 * n + 5, 1e9);
    }
    int merge(int x, int y) {
        return min(x, y);
    }
    int query(int node, int start, int end, int l, int r) {
        // l r start end OR start end l r
        if(r < start || end < l) {
            return 1e9;
        }
        // l start end r
        if(l <= start && end <= r) {
            return st[node];
        }
        int mid = (start + end) / 2;
        return merge(query(2 * node + 1, start, mid, l, r), query(2 * node + 2, mid + 1, end, l, r));
    }
    void update(int node, int start, int end, int idx, int val) {
        if(start > idx || end < idx) {
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
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<SegmentTree> rows, cols;
        for(int i = 0; i < n; i++) {
            SegmentTree st(m);
            rows.push_back(st);
        }
        for(int i = 0; i < m; i++) {
            SegmentTree st(n);
            cols.push_back(st);
        }
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        dp[n - 1][m - 1] = 1;
        rows[n - 1].update(0, 0, m - 1, m - 1, 1);
        cols[m - 1].update(0, 0, n - 1, n - 1, 1);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(grid[i][j] == 0) {
                    continue;
                }
                if(j + 1 < m) {
                    dp[i][j] = min(dp[i][j], 1 + rows[i].query(0, 0, m - 1, j + 1, min(m - 1, j + grid[i][j])));
                }
                if(i + 1 < n) {
                    dp[i][j] = min(dp[i][j], 1 + cols[j].query(0, 0, n - 1, i + 1, min(n - 1, i + grid[i][j])));
                }
                rows[i].update(0, 0, m - 1, j, dp[i][j]);
                cols[j].update(0, 0, n - 1, i, dp[i][j]);
            }
        }
        return dp[0][0] == 1e9 ? -1 : dp[0][0];
    }
};