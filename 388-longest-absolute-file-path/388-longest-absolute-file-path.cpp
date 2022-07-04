class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        input.push_back('\n');
        vector<string> tokens;
        string s = "";
        int ans = 0;
        for(char c: input) {
            if(c == '\n') {
                tokens.push_back(s);
                s = "";
            }
            else {
                s += c;
            }
        }
        stack<int> st;
        st.push(0);
        for(auto x: tokens) {
            int level = 0;
            for(int i = 0; i < (int)x.size(); i++) {
                if(x[i] == '\t') {
                    level = i + 1;
                }
            }
            while(level < (int)st.size() - 1) {
                st.pop();
            }
            int len = st.top() + ((int)x.size() - level) + 1;
            st.push(len);
            if(x.find('.') != std::string::npos) {
                ans = max(ans,len - 1);
            }
        }
        return ans;
    }
};