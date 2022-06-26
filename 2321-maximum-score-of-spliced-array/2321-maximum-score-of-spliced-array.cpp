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
    int solve(vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector<int> aux(n);
        int sum = accumulate(b.begin(), b.end(), 0);
        for(int i = 0; i < n; i++) {
            aux[i] = a[i] - b[i];
        }
        return sum + maxSubArray(aux);
    } 
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        ans = max(ans, solve(nums1, nums2));
        ans = max(ans, solve(nums2, nums1));
        return ans;
    }
};