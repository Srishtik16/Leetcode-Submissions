class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        int sum = 0;
        vector<int> pref(n, 0);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            if(i + b >= n) {
                sum += nums[i];
                dp[i] = sum;
            }
            else {
                sum = sum + nums[i] - nums[i + b];
                dp[i] = max({sum, dp[i], dp[i + 1]});
            }
        }
        int ans = pref[a - 1] + dp[a];
        for(int i = a; i < (n - b); i++) {
            ans = max(ans, pref[i] - pref[i - a] + dp[i + 1]);
        }
        swap(a, b);
        dp.assign(n + 1, 0);
        sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(i + b >= n) {
                sum += nums[i];
                dp[i] = sum;
            }
            else {
                sum = sum + nums[i] - nums[i + b];
                dp[i] = max({sum, dp[i], dp[i + 1]});
            }
        }
        ans = max(ans, pref[a - 1] + dp[a]);
        for(int i = a; i < (n - b); i++) {
            ans = max(ans, pref[i] - pref[i - a] + dp[i + 1]);
        }
        return ans;
    }
};