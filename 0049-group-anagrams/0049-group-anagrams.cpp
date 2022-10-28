class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(auto x: strs) {
            string xx = x;
            sort(xx.begin(), xx.end());
            m[xx].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x: m) {
            ans.push_back(x.second);
        }
        return ans;
    }
};