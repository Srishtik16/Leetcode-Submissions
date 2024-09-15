class Solution {
public:
    int findTheLongestSubstring(string s) {
        // prefix bitmask approach
        int n = s.size();
        int pref = 0, ans = 0;
        vector<int> m(32, -1);
        map<char, int> mv;
        mv['a'] = 1, mv['e'] = 2, mv['i'] = 4, mv['o'] = 8, mv['u'] = 16;
        for(int i = 0; i < n; i++) {
            pref ^= mv[s[i]];
            if(m[pref] == -1 && pref != 0) {
                m[pref] = i;
            }
            ans = max(ans, i - m[pref]);
        }
        return ans;
    }
};