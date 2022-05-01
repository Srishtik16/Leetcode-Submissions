class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }
        sort(vec.begin(), vec.end());
        int left = 0, right = n - 1;
        while(left < right) {
            if(vec[left].first + vec[right].first == target) {
                return {vec[left].second, vec[right].second};
            }
            else if(vec[left].first + vec[right].first < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return {-1, -1};
    }
};