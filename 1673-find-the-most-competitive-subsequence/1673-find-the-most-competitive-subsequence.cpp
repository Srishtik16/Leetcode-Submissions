class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;
        int times = n - k;
        for(auto x: nums) {
            while(!st.empty() && times > 0 && x < st.top()) {
                st.pop();
                times--;
            }
            st.push(x);
        }
        while(st.size() > k) {
            st.pop();
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};