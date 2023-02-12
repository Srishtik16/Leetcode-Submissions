class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        auto toBinary = [&](int val) {
            if(val == 0) {
                return to_string(0);
            }
            string bin = "";
            while(val > 0) {
                bin += (val % 2 == 0 ? '0' : '1');
                val /= 2;
            }
            reverse(bin.begin(), bin.end());
            return bin;
        };
        vector<vector<int>> ans((int)queries.size(), {-1, -1});
        int index = 0;
        map<string, vector<int>> m;
        for(auto &q: queries) {
            string t = toBinary(q[0] ^ q[1]);
            m[t].push_back(index++);
        }
        for(auto i: m["110"]) {
            cout << i << endl;
        }
        for(int window = 1; window <= min(32, n); window++) {
            string t = "";
            for(int i = 0; i < window; i++) {
                t += s[i];
            }
            if(m.find(t) != m.end()) {
                for(auto it: m[t]) {
                    if(ans[it] == vector<int>(2, -1)) {
                        ans[it] = {0, window - 1};
                    }
                }
            }
            for(int i = window; i < n; i++) {
                t.erase(t.begin());
                t += s[i];
                if(m.find(t) != m.end()) {
                    for(auto it: m[t]) {
                        if(ans[it] == vector<int>(2, -1)) {
                            ans[it] = {i - window + 1, i};
                        }
                    }
                    
                }
            }
        }
        return ans;
    }
};