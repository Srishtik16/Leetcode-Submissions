class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](const int &x, const int &y) {
            return x % 2 < y % 2;
        });
        return nums;
    }
};