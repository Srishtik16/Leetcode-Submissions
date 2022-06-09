class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> prev(n), next(n);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && a[s.top()] >= a[i]) {
                s.pop();
            }
            if(s.empty()) {
                prev[i] = -1;
            }
            else {
                prev[i] = s.top();
            }
            s.push(i);
        }
        while(!s.empty()) {
            s.pop();
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && a[s.top()] >= a[i]) {
                s.pop();
            }
            if(s.empty()) {
                next[i] = n;
            }
            else {
                next[i] = s.top();
            }
            s.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, (abs(prev[i] - next[i]) - 1) * a[i]);
        }
        return ans;
    }
};