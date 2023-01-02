class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        deque<char> dq(s.begin(), s.end());
        int moves = 0;
        while(dq.size() > 1 && dq.front() == dq.back()) {
            char c = dq.front();
            while(!dq.empty() && dq.front() == c) {
                moves++;
                dq.pop_front();
            }
            while(!dq.empty() && dq.back() == c) {
                moves++;
                dq.pop_back();
            }
        }
        return n - moves;
    }
};