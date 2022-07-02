class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int Or = accumulate(nums.begin(), nums.end(), 0, [&](const int &x, const int &y) {
            return x | y;
        });
        return Or * (1 << (n - 1));
    }
};