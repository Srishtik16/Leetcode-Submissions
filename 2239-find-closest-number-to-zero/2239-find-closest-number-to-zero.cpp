class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](const int &x, const int &y) {
            if(abs(x) == abs(y)) {
                return x > y;
            }
            return abs(x) < abs(y);
        });
        return nums.front();
    }
};