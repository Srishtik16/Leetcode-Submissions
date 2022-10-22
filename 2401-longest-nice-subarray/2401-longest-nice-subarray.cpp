class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, ans = 0;
        vector<int> bits(32, 0);
        while(l <= r && r < n) {
            for(int i = 30; i >= 0; i--) {
                if((1LL << i) & nums[r]) {
                    bits[i]++;
                }
            }
            while(*max_element(bits.begin(), bits.end()) >= 2) {
                for(int i = 30; i >= 0; i--) {
                    if((1LL << i) & nums[l]) {
                        bits[i]--;
                    }
                }
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};