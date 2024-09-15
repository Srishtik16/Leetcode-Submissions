class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [&](const auto &x, const auto &y) {
            if(x.size() == y.size()) {
                return x > y;
            }
            return x.size() > y.size();
        });
        return nums[k - 1];
    }
};