class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> st;
        for(char c: expression) {
            if(c == '(' || c == '|' || c == '&' || c == '!' || c == 't' || c == 'f') {
                st.push(c);
            }
            else if(c == ')') {
                string exp = "";
                while(!st.empty() && st.top() != '(') {
                    exp += st.top();
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                string res = "";
                if(op == '!') {
                    res = exp[0] == 't' ? 'f' : 't';
                }
                else if(op == '&') {
                    res = find(exp.begin(), exp.end(), 'f') == exp.end() ? 't' : 'f';
                }
                else {
                    res = find(exp.begin(), exp.end(), 't') == exp.end() ? 'f' : 't';
                }
                st.push(res[0]);
            }
        }
        return st.top() == 't';
    }
};