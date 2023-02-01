class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            nums[i] ^= nums[i - 1];
        }
        vector<int> ans;
        while(n--) {
            int pref = nums.back();
            nums.pop_back();
            int k = 0;
            for(int i = 0; i < maximumBit; i++) {
                if((1LL << i) & pref) {
                    continue;
                }
                k |= (1LL << i);
            }
            ans.push_back(k);
        }
        return ans;
    }
};