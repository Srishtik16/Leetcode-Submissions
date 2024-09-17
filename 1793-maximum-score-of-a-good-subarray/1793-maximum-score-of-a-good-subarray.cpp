class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        // Precompute Logs
        vector<int> LOG(n + 1);
        LOG[1] = 0;
        for(int i = 2; i <= n; i++) {
            LOG[i] = LOG[i / 2] + 1;
        }
        // Implement Sparse Table for min
        // st[i][j] = min in range [i, i + 2^j - 1]
        // st[i][j] = merge(st[i][j - 1], st[i + (1 << j - 1)][j - 1])
        // st[i][0] = a[i]
        vector<vector<int>> st(n + 1, vector<int>(20, INT_MAX));
        for(int i = 0; i < n; i++) {
            st[i][0] = nums[i];
        }
        for(int j = 1; j < 20; j++) {
            for(int i = 0; i + (1 << j) - 1 < n ; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
        auto query = [&](int l, int r) {
            int j = LOG[r - l + 1];
            return min(st[l][j], st[r - (1LL << j) + 1][j]);
        };
        int res = 0;
        for(int i = 0; i < n; i++) {
            int l = 0, r = i, ans = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(query(mid, i) == nums[i]) {
                    ans = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            int left = ans;
            l = i, r = n - 1, ans = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(query(i, mid) == nums[i]) {
                    ans = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            int right = ans;
            if(left <= k && k <= right) {
                res = max(res, nums[i] * (right - left + 1));
            }
        }
        return res;
    }
};