class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int wholeDiff = INT_MAX, wholeSum = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            int sum = target - nums[i];
            int minDiff = INT_MAX, minSum = 0;
            vector<int> res;
            while(l < r) {
                if(nums[l] + nums[r] == sum) {
                    int diff = abs(nums[l] + nums[r] - sum);
                    if(diff < minDiff) {
                        minDiff = diff;
                        minSum = nums[l] + nums[r];
                        res = {nums[l], nums[r]};
                    }
                    break;
                }
                else if(nums[l] + nums[r] > sum) {
                    int diff = abs(nums[l] + nums[r] - sum);
                    if(diff < minDiff) {
                        minDiff = diff;
                        minSum = nums[l] + nums[r];
                        res = {nums[l], nums[r]};
                    }
                    r--;
                }
                else {
                    int diff = abs(nums[l] + nums[r] - sum);
                    if(diff < minDiff) {
                        minDiff = diff;
                        minSum = nums[l] + nums[r];
                        res = {nums[l], nums[r]};
                    }
                    l++;
                }
            }
            int ssum = minSum + nums[i];
            if(abs(ssum - target) < wholeDiff) {
                wholeDiff = abs(ssum - target);
                wholeSum = ssum;
                ans = res;
                ans.push_back(nums[i]);
            }
        }
        return ans[0] + ans[1] + ans[2];
    }
};