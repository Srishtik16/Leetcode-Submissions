class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int, int> indeg;
        for(auto x: matches) {
            indeg[x[0]] = indeg[x[0]];
            indeg[x[1]]++;
        }
        for(int i = 1; i <= 1e5; i++) {
            if(indeg.find(i) != indeg.end() && indeg[i] == 0) {
                ans[0].push_back(i);
            }
            else if(indeg.find(i) != indeg.end() && indeg[i] == 1) {
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};