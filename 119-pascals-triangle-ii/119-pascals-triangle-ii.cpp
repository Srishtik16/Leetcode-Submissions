class Solution {
public:
    vector<int> getRow(int n) {
        auto ncr = [&](int n, int r) {
            long long ptr = n, ans = 1;
            for(int i = 1; i <= r; i++) {
                ans *= ptr;
                ans /= i;
                ptr--;
            }
            return ans;
        };
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            ans.push_back(ncr(n, i));
        }
        return ans;
    }
};