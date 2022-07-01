class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = accumulate(nums.begin(), nums.end(), 0, [&](const int &x, const int &y) {
            return x | y;
        });
        int n = nums.size(), ans = 0;
        for(int mask = 1; mask < (1 << n); mask++) {
            int subsetOr = 0;
            for(int i = 0; i < n; i++) {
                if((1 << i) & mask) {
                    subsetOr |= nums[i];
                }
            }
            if(subsetOr == maxOr) {
                ans++;
            }
        }
        return ans;
    }
};