class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        n /= 2;
        long long sum = 0;
        map<long long, vector<long long>> store;
        for(int mask = 0; mask < (1LL << n); mask++) {
            sum = 0;
            for(int j = 0; j < n; j++) {
                if((1LL << j) & mask) {
                    sum += nums[j];
                }
                else {
                    sum -= nums[j];
                }
            }
            store[__builtin_popcount(mask)].push_back(sum);
        }
        for(auto &x: store) {
            sort(x.second.begin(), x.second.end());
        }
        int ans = INT_MAX;
        for(int mask = 0; mask < (1LL << n); mask++) {
            sum = 0;
            for(int j = 0; j < n; j++) {
                if((1LL << j) & mask) {
                    sum += nums[j + n];
                }
                else {
                    sum -= nums[j + n];
                }
            }
            int used = __builtin_popcount(mask);
            auto it = lower_bound(store[n - used].begin(), store[n - used].end(), -sum);
            if(it != store[n - used].end()) {
                ans = min<int>(ans, abs(*it + sum));
            }
            if(it != store[n - used].begin()) {
                it--;
                ans = min<int>(ans, abs(*it + sum));
            }
        }
        return ans;
    }
};