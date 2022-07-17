class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int ans = 0;
        for(char c: s) {
            if(c == '(') {
                if(st.empty() || st.top() == 2) {
                    st.push(2);
                }
                else {
                    st.pop();
                    st.push(2);
                    ans++;
                }
            }
            else {
                if(st.empty()) {
                    st.push(1);
                    ans++;
                }
                else if(st.top() == 1) {
                    st.pop();
                }
                else if(st.top() == 2) {
                    st.pop();
                    st.push(1);
                }
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};