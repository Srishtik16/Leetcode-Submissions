class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        multiset<pair<int, char>, greater<pair<int, char>>> ms;
        if(a > 0) {
            ms.insert({a, 'a'});
        }
        if(b > 0) {
            ms.insert({b, 'b'});
        }
        if(c > 0) {
            ms.insert({c, 'c'});
        }
        while(!ms.empty()) {
            cout << ans << endl;
            if(ans.size() ==  a + b + c) {
                return ans;
            }
            auto f = *ms.begin();
            ms.erase(ms.begin());
            if(ans.size() < 2) {
                ans += f.second;
                f.first--;
                if(f.first > 0) {
                    ms.insert(f);
                }
            }
            else if(ans.back() == f.second && ans[ans.size() - 2] == f.second) {
                cout << "HERE" << endl;
                if(ms.empty()) {
                    return ans;
                }
                auto ff = *ms.begin();
                cout << ff.first << " " << ff.second << endl;
                ans += ff.second;
                ff.first--;
                ms.erase(ms.begin());
                ms.insert(f);
                if(ff.first > 0) {
                    ms.insert(ff);
                }
            }
            else {
                ans += f.second;
                f.first--;
                if(f.first > 0) {
                    ms.insert(f);
                }
            }
        }
        return ans;
    }
};