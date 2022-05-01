class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int l = j + 1, r = n - 1;
                int tar = target - (nums[i] + nums[j]);
                while(l < r) {
                    if(nums[l] + nums[r] == tar) {
                        vector<int> val = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(val);
                        while(l < r && nums[l] == val[2]) {
                            l++;
                        }
                        while(l < r && nums[r] == val[3]) {
                            r--;
                        }
                    }
                    else if(nums[l] + nums[r] < tar) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) {
                    j++;
                }
            }
            while(i + 1 < n && nums[i + 1] == nums[i]) {
                i++;
            }
        }
        return ans;
    }
};