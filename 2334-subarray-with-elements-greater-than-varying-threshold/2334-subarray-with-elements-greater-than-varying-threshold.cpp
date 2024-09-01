class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        // For element i as the minimum, find largest subarray to make the limit small
        int n = nums.size();
        stack<int> st1, st2;
        vector<int> prev(n), next(n);
        for(int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
            while(!st1.empty() && nums[i] <= nums[st1.top()]) {
                st1.pop();
            }
            while(!st2.empty() && nums[j] <= nums[st2.top()]) {
                st2.pop();
            }
            prev[i] = st1.empty() ? -1 : st1.top();
            next[j] = st2.empty() ? n : st2.top();
            st1.push(i);
            st2.push(j);
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > (threshold * 1.0) / (next[i] - prev[i] - 1)) {
                return next[i] - prev[i] - 1;
            }
        }
        return -1;
    }
};