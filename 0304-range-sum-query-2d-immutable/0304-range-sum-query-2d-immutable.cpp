class NumMatrix {
public:
    vector<vector<int>> pref;
    int n, m;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        pref = matrix;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i - 1 >= 0 && j - 1 >= 0) {
                    pref[i][j] -= pref[i - 1][j - 1];
                }
                if(i - 1 >= 0) {
                    pref[i][j] += pref[i - 1][j];
                }
                if(j - 1 >= 0) {
                    pref[i][j] += pref[i][j - 1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s1 = row1 >= 1 ? pref[row1 - 1][col2] : 0;
        int s2 = col1 >= 1 ? pref[row2][col1 - 1] : 0;
        int s3 = row1 >= 1 && col1 >= 1 ? pref[row1 - 1][col1 - 1] : 0;
        return pref[row2][col2] - s1 - s2 + s3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */