class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 != i % 2) {
                int j = i + 1;
                while(j < n && nums[j] % 2 != i % 2) {
                    j++;
                }
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};