class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> s;
        for(auto &ele: circles) {
            for(int x = ele[0] - ele[2]; x <= ele[0] + ele[2]; x++) {
                for(int y = ele[1] - ele[2]; y <= ele[1] + ele[2]; y++) {
                    if((ele[0] - x) * (ele[0] - x) + (ele[1] - y) * (ele[1] - y) <= ele[2] * ele[2]) {
                        s.insert({x, y});
                    }
                }
            }
        }
        return (int)s.size();
    }
};