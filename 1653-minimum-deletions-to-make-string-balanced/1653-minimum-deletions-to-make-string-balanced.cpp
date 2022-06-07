class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> pref(n, 0), suff(n, 0);
        pref[0] = s[0] == 'b' ? 1 : 0;
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (s[i] == 'b');
        }
        suff[n - 1] = s.back() == 'a' ? 1 : 0;
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + (s[i] == 'a');
        }
        int ans = min(pref.back(), suff[0]);
        for(int i = 0; i < n - 1; i++) {
            ans = min(ans, pref[i] + suff[i + 1]);
        }
        return ans;
    }
};