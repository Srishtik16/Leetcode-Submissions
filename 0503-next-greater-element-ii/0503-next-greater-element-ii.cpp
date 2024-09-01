class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> nNums = nums;
        for(auto x: nNums) {
            nums.push_back(x);
        }
        int n = nums.size();
        vector<int> nge(n, -1);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[i] >= nums[st.top()]) {
                st.pop();
            }
            nge[i] = st.empty() ? -1 : nums[st.top()];
            st.push(i);
        }
        n = nNums.size();
        while(nge.size() > n) {
            nge.pop_back();
        }
        return nge;
    }
};