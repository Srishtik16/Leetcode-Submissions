class Solution {
public:
    vector<int> st;
    void update(int node, int start, int end, int idx, int val) {
        // cout << start << " " << end << endl;
        if(idx == start && start == end) {
            st[node] = val;
            return;
        }
        if(start > idx || end < idx) {
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, idx, val);
        update(2 * node + 2, mid + 1, end, idx, val);
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }
    int find(int node, int start, int end, int k) {
        // cout << start << " " << end << endl;
        if(start == end) {
            return start;
        }
        int mid = (start + end) / 2;
        if(st[2 * node + 1] < k) {
            return find(2 * node + 2, mid + 1, end, k - st[2 * node + 1]);
        }
        else {
            return find(2 * node + 1, start, mid, k);
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](const auto &x, const auto &y) {
            if(x[0] == y[0]) {
                return x[1] > y[1];
            }
            return x[0] < y[0];
        });
        int n = people.size();
        st.assign(4 * n + 5, 0);
        for(int i = 0; i < n; i++) {
            update(0, 0, n, i, 1);
        }
        vector<vector<int>> ans(n);
        for(auto x: people) {
            int ind = find(0, 0, n, x[1] + 1);
            ans[ind] = x;
            update(0, 0, n, ind, 0);
        }
        return ans;
    }
};