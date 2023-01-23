class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int moves = 0;
        for(char c: s) {
            if(c == '(') {
                st.push(c);
            }
            else {
                if(st.empty()) {
                    moves++;
                }
                else {
                    st.pop();
                }
            }
        }
        while(!st.empty()) {
            moves++;
            st.pop();
        }
        return moves;
    }
};