class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // dp[i] = best answer if we take upto ith element value as the largest value in set
        // Its optimal to take all occurence of a number if we take one of them
        // If we take i, we can take only upto dp[i - 2] + all i's occurences, else dp[i - 1]
        map<int, int> m;
        for(auto x: nums) {
            m[x]++;
        }
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> dp(mx + 1, 0);
        dp[(*m.begin()).first] = (*m.begin()).second * (*m.begin()).first;
        for(int i = 2; i <= mx; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + m[i] * i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};