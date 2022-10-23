class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(auto x: grid) {
            for(auto y: x) {
                cnt += y < 0;
            }
        }
        return cnt;
    }
};