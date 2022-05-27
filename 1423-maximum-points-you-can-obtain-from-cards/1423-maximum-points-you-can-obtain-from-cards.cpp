class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        vector<int> suff(n);
        suff[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + a[i];
        }
        int pref = 0, ans = suff[n - k];
        for(int i = 0; i < k; i++) {
            pref += a[i];
            int ind = n - (k - i - 1);
            if(ind == n) {
                ans = max(ans, pref);
                continue;
            }
            int suf = suff[ind];
            ans = max(ans, pref + suf);
        }
        return ans;
    }
};