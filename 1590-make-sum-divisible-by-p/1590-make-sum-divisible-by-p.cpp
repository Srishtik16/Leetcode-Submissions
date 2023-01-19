class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k, int mod) {
        map<int, int> m;
        long long pref = 0, n = (int)nums.size(), ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            pref += nums[i];
            if(((pref % k) + k) % k == mod) {
                ans = min<long long>(ans, i + 1);
            }
            if(m.find((((pref - mod) % k) + k) % k) != m.end()) {
                ans = min<long long>(ans, i - m[(((pref - mod) % k) + k) % k]);
            }
            m[((pref % k) + k) % k] = i;
        }
        return ans;
    }
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(begin(nums), end(nums), 0LL);
        sum %= p;
        if(sum == 0) {
            return 0;
        }
        return subarraysDivByK(nums, p, sum) >= size(nums) ? -1 : subarraysDivByK(nums, p, sum);
    }
};