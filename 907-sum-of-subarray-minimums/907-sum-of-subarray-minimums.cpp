class Solution {
public:
    int sumSubarrayMins(vector<int> &a) {
        int n = a.size();
        vector<int> prev(n), next(n);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && a[s.top()] > a[i]) {
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
        // for(int i = 0; i < n; i++) {
        //     cout << prev[i] << " " << next[i] << endl;
        // }
        const int MOD = 1e9 + 7;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int left = i - prev[i];
            int right = next[i] - i;
            // cout << a[i] << " " << left << " " << right << endl;
            ans += a[i] * 1LL * (left) * 1LL * (right);
            ans %= MOD;
        }
        return ans;
    }
};