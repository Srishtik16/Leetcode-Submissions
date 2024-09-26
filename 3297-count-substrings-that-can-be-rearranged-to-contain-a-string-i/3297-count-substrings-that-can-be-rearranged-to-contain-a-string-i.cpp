class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        // Count substrings ending at i
        // Binary search for that
        // We need prefix sums for character count in a range
        int n = word1.size();
        unordered_map<char, int> m;
        for(char c: word2) {
            m[c]++;
        }
        vector<vector<int>> pref(n, vector<int>(26, 0));
        pref[0][word1[0] - 'a'] = 1;
        for(int i = 1; i < n; i++) {
            for(char c = 'a'; c <= 'z'; c++) {
                pref[i][c - 'a'] = pref[i - 1][c - 'a'] + (word1[i] == c);
            }
        }
        long long res = 0;
        for(int i = 0; i < n; i++) {
            int l = 0, r = i, ans = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                bool ok = false;
                for(int j = 0; j < 26; j++) {
                    ok |= (pref[i][j] - (mid > 0 ? pref[mid - 1][j] : 0) < m[char(j + 'a')]);
                    if(ok) {
                        break;
                    }
                }
                if(ok) {
                    ans = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            if(ans == -1) {;
                res += i + 1;
            }
            else {
                res += i + 1;
                res -= (i - ans + 1);
            }
        }
        return res;
    }
};