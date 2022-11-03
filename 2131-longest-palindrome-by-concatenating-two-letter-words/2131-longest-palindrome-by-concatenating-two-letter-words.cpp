class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        multiset<string> ms(words.begin(), words.end());
        int ans = 0;
        bool centre = false;
        while(!ms.empty()) {
            string s = *ms.begin();
            string rev = s;
            reverse(rev.begin(), rev.end());
            ms.erase(ms.begin());
            auto it = ms.find(rev);
            if(it != ms.end()) {
                ms.erase(it);
                ans += 4;
            }
            else if(it == ms.end() && !centre) {
                if(s[0] == s[1]) {
                    centre = true;
                    ans += 2;
                }
            }
        }
        return ans;
    }
};