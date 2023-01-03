class Solution {
public:
    int minFlips(string s) {
        s += s;
        string s1 = "", s2 = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
            s1 += (i % 2 == 0 ? '1' : '0');
            s2 += (i % 2 == 0 ? '0' : '1');
        }
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < n / 2; i++) {
            ans1 += s1[i] != s[i];
            ans2 += s2[i] != s[i];
        }
        int ans = min(ans1, ans2);
        for(int i = n / 2; i < n; i++) {
            ans1 -= s1[i - n / 2] != s[i - n / 2];
            ans2 -= s2[i - n / 2] != s[i - n / 2];
            ans1 += s1[i] != s[i];
            ans2 += s2[i] != s[i];
            ans = min({ans, ans1, ans2});
        }
        return ans;
    }
};