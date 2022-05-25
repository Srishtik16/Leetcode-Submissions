class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        map<char, int> ms, mt;
        for(char c: t) {
            mt[c]++;
        }
        int l = 0, r = 0, ans = INT_MAX;
        pair<int, int> res = {-1, -1};
        vector<bool> vis(n, false);
        while(l <= r && r < n) {
            if(!vis[r]) {
                ms[s[r]]++;
                vis[r] = true;
            }
            bool ok = true;
            for(auto x: mt) {
                if(ms[x.first] < x.second) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ans = min(ans, r - l + 1);
                if(ans == r - l + 1) {
                    res = {l, ans};
                }
                ms[s[l]]--;
                l++;
            }
            else {
                r++;
            }
        }
        if(ans == INT_MAX) {
            return "";
        }
        string answer = s.substr(res.first, res.second);
        return answer;
    }
};