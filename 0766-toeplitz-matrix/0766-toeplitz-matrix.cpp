class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool ok = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int l = i, r = j;
                set<int> s;
                while(l < n && r < m) {
                    s.insert(matrix[l][r]);
                    l++;
                    r++;
                }
                ok &= s.size() == 1;
            }
        }
        return ok;
    }
};