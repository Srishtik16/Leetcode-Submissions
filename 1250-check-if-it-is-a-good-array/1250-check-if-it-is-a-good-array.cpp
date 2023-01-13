class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [&](const int &x, const int &y) {
            return __gcd(x, y);
        }) == 1;
    }
};