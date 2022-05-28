class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    continue;
                }
                matrix[i][j] = 1 + min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});
            }
        }
        int ans = 0;
        for(auto &x: matrix) {
            ans += accumulate(x.begin(), x.end(), 0);
        }
        return ans;
    }
};