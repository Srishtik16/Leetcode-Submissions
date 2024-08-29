class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<int, int> m;
        int l = 0, r = 0, ans = 0;
        while(r < n) {
            m[s[r]]++;
            if(m.size() < r - l + 1) {
                m[s[l]]--;
                if(m[s[l]] == 0) {
                    m.erase(s[l]);
                }
                l++;
            }
            else {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};