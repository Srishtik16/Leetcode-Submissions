class Solution {
public:
    int longestValidParentheses(string s) {
        // iterate left to right
        // when we get ')' matching, we update range and take max
        stack<int> st;
        int n = s.size();
        vector<bool> valid(n);
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                if(!st.empty()) {
                    valid[st.top()] = valid[i] = true;
                    st.pop();
                }
            }
        }
        int ans = 0, l = 0;
        for(auto x: valid) {
            ans = max(ans, l = x ? l + 1 : 0);
        }
        return ans;
    }
};