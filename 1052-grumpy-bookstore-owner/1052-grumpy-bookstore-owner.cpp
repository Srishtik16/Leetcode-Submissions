class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> g(n, 0);
        for(int i = 0; i < n; i++) {
            g[i] = customers[i] * (1 - grumpy[i]);
        }
        vector<int> pg(n, 0), sg(n, 0);
        pg[0] = g[0];
        for(int i = 1; i < n; i++) {
            pg[i] = pg[i - 1] + g[i];
        }
        sg[n - 1] = g[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            sg[i] = sg[i + 1] + g[i];
        }
        vector<int> pref = customers;
        for(int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }
        auto range = [&](int l, int r) {
            if(l < 0 || r >= n || l > r) {
                return -1;
            }
            return pref[r] - (l > 0 ? pref[l - 1] : 0);
        };
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int sum = range(i, i + minutes - 1);
            if(sum != -1) {
                int satisfied = sum + (i > 0 ? pg[i - 1] : 0) + (i + minutes - 1 < n - 1 ? sg[i + minutes] : 0);
                ans = max(ans, satisfied);
            }
        }
        return ans;
    }
};