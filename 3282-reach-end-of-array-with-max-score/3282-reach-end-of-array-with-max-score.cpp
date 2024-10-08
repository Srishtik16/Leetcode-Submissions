class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, n);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[i] >= nums[st.top()]) {
                st.pop();
            }
            nge[i] = st.empty() ? n - 1 : st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n - 1; i = nge[i]) {
            ans += (nge[i] - i) * 1LL * nums[i];
        }
        return ans;
    }
};