class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if(n < 10) {
            return vector<string>();
        }
        int l = 0, r = 9;
        map<string, int> m;
        while(l <= r && r < n) {
            string ss = s.substr(l, r - l + 1);
            m[ss]++;
            l++;
            r++;
        }
        vector<string> ans;
        for(auto x: m) {
            if(x.second > 1) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};