class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xor = accumulate(nums.begin(), nums.end(), 0, [&](const int &x, const int &y) {
            return x ^ y;
        });
        for(int i = 0; i <= (int)nums.size(); i++) {
            Xor ^= i;
        }
        return Xor;
    }
};