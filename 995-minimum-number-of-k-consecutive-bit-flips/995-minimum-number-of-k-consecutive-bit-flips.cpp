class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> flips(n, false);
        bool flipped = false;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i >= k && flips[i - k]) {
                flipped ^= 1;
            }
            if((flipped ? 1 : 0) == nums[i]) {
                if(i + k > n) {
                    return -1;
                }
                ans++;
                flips[i] = true;
                flipped ^= 1;
            }
        }
        return ans;
    }
};