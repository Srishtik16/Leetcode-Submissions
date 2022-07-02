class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<long long> hash(32);
        for(int i = 0; i <= 31; i++) {
            for(int j = 0; j < n; j++) {
                if(nums[j] & (1LL << i)) {
                    hash[i]++;
                }
            }
        }
        long long ans = 0;
        // 31st bit 1 to signify its negative
        for(int i = 31; i >= 0; i--) {
            if(hash[i] % 3 == 0) {
                continue;
            }
            ans |= (1LL << i);
        }
        return ans;
    }
};