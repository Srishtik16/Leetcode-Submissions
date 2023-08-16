class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> ms;
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ms.insert(nums[i]);
        }
        ans.push_back(*ms.rbegin());
        for(int i = k; i < n; i++) {
            ms.erase(ms.find(nums[i - k]));
            ms.insert(nums[i]);
            ans.push_back(*ms.rbegin());
        }
        return ans;
    }
};