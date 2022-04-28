class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ncr(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= n; i++) {
            ncr[i][i] = 1;
            ncr[i][0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans;
        for(int row = 1; row <= n; row++) {
            vector<int> val;
            for(int i = 0; i < row; i++) {
                val.push_back(ncr[row - 1][i]);
            }
            ans.push_back(val);
        }
        return ans;
    }
};