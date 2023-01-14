class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> a, b;
        for(int i = 0; i < n; i++) {
            if(i < n / 2) {
                a.push_back(nums[i]);
            }
            else {
                b.push_back(nums[i]);
            }
        }
        auto genSubsetSums = [&](vector<int> &a) {
            int n = a.size();
            vector<int> sums;
            for(int mask = 0; mask < (1LL << n); mask++) {
                int sum = 0;
                for(int i = 0; i < n; i++) {
                    if(mask & (1LL << i)) {
                        sum += a[i];
                    }
                }
                sums.push_back(sum);
            }
            return sums;
        };
        auto sa = genSubsetSums(a);
        auto sb = genSubsetSums(b);
        sort(sb.begin(), sb.end());
        int ans = INT_MAX;
        for(auto &x: sa) {
            int need = goal - x;
            auto it = lower_bound(sb.begin(), sb.end(), need);
            auto it1 = upper_bound(sb.begin(), sb.end(), need);
            if(it1 != sb.begin()) {
                advance(it1, -1);
            }
            int s1 = (it != end(sb)) ? (x + *it) : x;
            int s2 = (it1 != end(sb)) ? (x + *it1) : x;
            ans = min({ans, abs(goal - s1), abs(goal - s2)});
        }
        return ans;
    }
};