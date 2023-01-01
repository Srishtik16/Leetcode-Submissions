class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int> single;
        for(auto x: mat) {
            for(auto y: x) {
                single.push_back(y);
            }
        }
        if(r * c != (int)single.size()) {
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int ptr = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                ans[i][j] = single[ptr++];
            }
        }
        return ans;
    }
};