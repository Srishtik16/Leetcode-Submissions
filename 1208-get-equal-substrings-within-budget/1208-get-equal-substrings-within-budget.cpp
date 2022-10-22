class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int l = 0, r = 0, ans = 0, cost = 0;
        while(l <= r && r < n) {
            cost += abs(s[r] - t[r]);
            while(cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};