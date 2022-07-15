using ll = long long;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        ll ans = 0;
        vector<unordered_set<string>> v(26);
        for(auto x: ideas) {
            v[x[0] - 'a'].insert(x.substr(1));
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                int cnt1 = 0, cnt2 = 0;
                for(auto x: v[i]) {
                    if(v[j].find(x) == v[j].end()) {
                        cnt1++;
                    }
                }
                for(auto x: v[j]) {
                    if(v[i].find(x) == v[i].end()) {
                        cnt2++;
                    }
                }
                ans += cnt1 * cnt2;
            }
        }
        return ans;
    }
};