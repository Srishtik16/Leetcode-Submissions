class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> index;
        int n = nums2.size();
        for(int i = 0; i < n; i++) {
            index[nums2[i]] = i;
        }
        stack<int> st;
        vector<int> nge(n, -1);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums2[i] >= nums2[st.top()]) {
                st.pop();
            }
            nge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        vector<int> ans;
        for(auto x: nums1) {
            int ind = nge[index[x]];
            ans.push_back(ind == -1 ? -1 : nums2[ind]);
        } 
        return ans;
    }
};