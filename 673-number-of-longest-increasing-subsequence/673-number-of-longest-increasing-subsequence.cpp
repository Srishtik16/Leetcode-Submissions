class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(dp[i] < dp[j] + 1) {
                        cnt[i] = cnt[j];
                        dp[i] = dp[j] + 1;
                    }
                    else if(dp[i] == dp[j] + 1) {
                        cnt[i] += cnt[j];
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        for(auto x: dp) {
            cout << x << " ";
        }
        cout << endl;
        for(auto x: cnt) {
            cout << x << " ";
        }
        cout << endl;
        int mx = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(mx == dp[i]) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};