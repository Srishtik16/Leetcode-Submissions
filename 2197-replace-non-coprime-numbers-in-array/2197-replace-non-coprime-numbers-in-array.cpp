class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for(auto x: nums) {
            while(!st.empty() && __gcd(x, st.top()) != 1) {
                x = (x * 1LL * st.top()) / __gcd(x, st.top());
                st.pop();
            }
            st.push(x);
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