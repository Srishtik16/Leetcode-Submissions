class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> m1;
        for(char c: chars) {
            m1[c]++;
        }
        int ans = 0;
        for(auto x: words) {
            map<char, int> m;
            for(char c: x) {
                m[c]++;
            }
            bool ok = false;
            for(auto x: m) {
                if(x.second > m1[x.first]) {
                    ok = true;
                }
            }
            if(!ok) {
                ans += x.size();
            }
        }
        return ans;
    }
};