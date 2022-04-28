class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<int> suff(n, INT_MAX);
        suff[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], a[i]);
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, suff[i + 1] - a[i]);
        }
        return ans;
    }
};