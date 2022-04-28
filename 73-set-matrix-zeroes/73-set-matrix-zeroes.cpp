class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows, cols;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(auto x: rows) {
            for(int j = 0; j < n; j++) {
                matrix[x][j] = 0;
            }
        }
        for(auto x: cols) {
            for(int j = 0; j < m; j++) {
                matrix[j][x] = 0;
            }
        }
    }
};