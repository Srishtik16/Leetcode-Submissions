class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return intervals;
        }
        multiset<vector<int>> ms(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        auto isOverlap = [&](auto range1, auto range2) {
            return min(range1[1], range2[1]) >= max(range1[0], range2[0]);
        };
        while(ms.size() > 1) {
            auto first = *ms.begin();
            ms.erase(ms.begin());
            auto second = *ms.begin();
            ms.erase(ms.begin());
            if(isOverlap(first, second)) {
                vector<int> overlapped = {min(first[0], second[0]), max(first[1], second[1])};
                ms.insert(overlapped);
            }
            else {
                ans.push_back(first);
                ms.insert(second);
            }
        }
        ans.push_back(*ms.begin());
        sort(ans.begin(), ans.end());
        return ans;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> intervals;
        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i - 1] >= 2) {
                intervals.push_back({nums[i - 1] + 1, nums[i] - 1});
            }
        }
        auto getSum = [&](int l, int r) {
            long long right = r * 1LL * (r + 1) / 2;
            long long left = l * 1LL * (l - 1) / 2;
            return right - left;
        };
        intervals.push_back({nums.back() + 1, INT_MAX});
        if(nums[0] > 1) {
            intervals.push_back({1, nums[0] - 1});
        }
        intervals = merge(intervals);
        long long ans = 0;
        for(auto x: intervals) {
            int need = min(x[1] - x[0] + 1, k);
            int l = x[0], r = l + need - 1;
            if(k == 0) {
                break;
            }
            k -= need;
            ans += getSum(l, r);
        }
        return ans;
    }
};