class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // l r --> number of unique characters in s[l, r].
        int n = s.size();
        int l = 0, r = 0;
        unordered_map<char, int> m;
        int ans = 0;
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