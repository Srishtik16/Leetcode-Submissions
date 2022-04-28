class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, ans = INT_MIN;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            curr += nums[i];
            ans = max(ans, curr);
            if(curr < 0)
            {
                ans = max(ans, curr);
                curr = 0;
            }
        }
        return ans;
    }
};