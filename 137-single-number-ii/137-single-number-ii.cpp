class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ones = 0, twos = 0;
        for(auto x: nums) {
            twos |= (ones & x);
            ones ^= x;
            int cancel = ~(ones & twos);
            ones &= cancel;
            twos &= cancel;
        }
        return ones;
    }
};