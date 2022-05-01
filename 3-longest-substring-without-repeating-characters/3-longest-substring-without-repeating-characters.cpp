class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int ans = 0;
        map<int, int> m;
        while(l <= r && r < n) {
            m[s[r]]++;
            if(m.size() == r - l + 1) {
                ans = max(ans, r - l + 1);
                r++;
            }
            else {
                m[s[l]]--;
                if(m[s[l]] <= 0) {
                    m.erase(s[l]);
                }
                l++;
                r++;
            }
        }
        return ans;
    }
};