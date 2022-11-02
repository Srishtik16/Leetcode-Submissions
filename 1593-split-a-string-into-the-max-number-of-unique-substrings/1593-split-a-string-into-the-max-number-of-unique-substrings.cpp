class Solution {
public:
    int recurse(string s, int index, set<string> &st) {
        if(index >= s.size()) {
            return 0;
        }
        int best = -1;
        for(int i = index; i < s.size(); i++) {
            string ss = s.substr(index, i - index + 1);
            if(st.find(ss) != st.end()) {
                continue;
            }
            else {
                st.insert(ss);
            }
            int nxt = recurse(s, i + 1, st);
            if(nxt >= 0) {
                best = max(best, 1 + nxt);
            }
            st.erase(st.find(ss));
        }
        return best;
    }
    int maxUniqueSplit(string s) {
        set<string> st;
        return recurse(s, 0, st);
    }
};