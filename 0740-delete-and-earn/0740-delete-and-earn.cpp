class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> dp, cnt;
        for(auto x: nums) {
            cnt[x]++;
        }
        for(auto x: cnt) {
            dp[x.first] = x.second * x.first;
        }
        for(int x = 2; x <= cnt.rbegin() -> first; x++) {
            dp[x] = max(dp[x - 1], dp[x - 2] + x * cnt[x]);
        } 
        int mx = 0;
        for(auto x: dp) {
            mx = max(mx, x.second);
        }
        return mx;
    }
};