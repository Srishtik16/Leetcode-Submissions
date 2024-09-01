class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && k > 0 && num[i] < num[st.top()]) {
                st.pop();
                k--;
            }
            st.push(i);
        }
        while(!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        string ans = st.empty() ? "0" : "";
        while(!st.empty()) {
            ans += num[st.top()];
            st.pop();
        }
        while(!ans.empty() && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};