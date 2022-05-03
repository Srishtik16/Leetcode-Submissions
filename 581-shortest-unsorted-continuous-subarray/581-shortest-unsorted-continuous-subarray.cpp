class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(), a.end());
        int left = 0, right = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(a[i] != nums[i]) {
                left = i;
                break;
            }
        }
        for(int i = (int)nums.size() - 1; i >= 0; i--) {
            if(a[i] != nums[i]) {
                right = i;
                break;
            }
        }
        return max(0, right - left + 1);
    }
};