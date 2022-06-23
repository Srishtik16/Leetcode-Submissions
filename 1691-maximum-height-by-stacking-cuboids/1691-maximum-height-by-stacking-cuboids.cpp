class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(auto &x: cuboids) {
            sort(x.begin(), x.end());
        }
        sort(cuboids.begin(), cuboids.end());
        auto check = [&](vector<int> &a, vector<int> &b) {
            return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
        };
        vector<int> dp(n);
        for(int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(check(cuboids[j], cuboids[i])) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};