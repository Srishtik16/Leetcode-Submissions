class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        map<int, int> m;
        for(auto x: nums) {
            m[x]++;
        }
        long long ans = 0;
        for(auto x: m) {
            for(int i = x.first; i <= mx; i += x.first) {
                long long index = x.second * 1LL * (n - (lower_bound(nums.begin(), nums.end(), i) - nums.begin()));
                ans += index;
                ans %= MOD;
            }
        }
        return ans;
    }
};