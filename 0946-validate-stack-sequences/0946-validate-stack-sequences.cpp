class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i = 0, j = 0;
        stack<int> s;
        bool ok = true;
        while(i < n && j < n) {
            if(!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
            else {
                s.push(pushed[i]);
                i++;
            }
        }
        if(i == n) {
            while(j < n) {
                if(s.top() == popped[j]) {
                    s.pop();
                    j++;
                }
                else {
                    ok = false;
                    break;
                }
            }
        }
        return ok;
    }
};