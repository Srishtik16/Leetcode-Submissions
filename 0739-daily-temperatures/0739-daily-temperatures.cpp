class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &a) {
        int n = a.size();
        stack<int> s;
        vector<int> nge(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && a[s.top()] <= a[i]) {
                s.pop();
            }
            if(s.empty()) {
                nge[i] = 0;
            }
            else {
                nge[i] = abs(s.top() - i);
            }
            s.push(i);
        }
        return nge;
    }
};