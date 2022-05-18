class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> score;
        for(auto x: nums) {
            score[x] += x;
        }
        int n = *max_element(nums.begin(), nums.end());
        vector<int> dp(n + 1, 0);
        for(auto x: score) {
            dp[x.first] = x.second;
        }
        for(int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + score[i]);
        }
        return dp.back();
    }
};