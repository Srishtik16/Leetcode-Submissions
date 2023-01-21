class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 1, r = min(n, m), ans = 0;
        vector<vector<int>> pref = mat;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0) {
                    pref[i][j] += pref[i - 1][j];
                }
                if(j > 0) {
                    pref[i][j] += pref[i][j - 1];
                }
                if(i > 0 && j > 0) {
                    pref[i][j] -= pref[i - 1][j - 1];
                }
            }
        }
        auto isValid = [&](vector<int> &pr, vector<int> &pc) {
            for(auto x: pr) {
                if(x < 0 || x >= n) {
                    return false;
                }
            }
            for(auto x: pc) {
                if(x < 0 || x >= m) {
                    return false;
                }
            }
            return true;
        };
        auto getSum = [&](int fromRow, int fromCol, int toRow, int toCol) {
            vector<int> pr = {fromRow, toRow};
            vector<int> pc = {fromCol, toCol};
            if(isValid(pr, pc)) {
                int sum = pref[toRow][toCol];
                if(fromRow - 1 >= 0) {
                    sum -= pref[fromRow - 1][toCol];
                }
                if(fromCol - 1 >= 0) {
                    sum -= pref[toRow][fromCol - 1];
                }
                if(fromRow - 1 >= 0 && fromCol - 1 >= 0) {
                    sum += pref[fromRow - 1][fromCol - 1];
                }
                return sum;
            }
            else {
                return INT_MAX;
            }
        };
        while(l <= r) {
            int mid = (l + r) / 2;
            int sum = INT_MAX;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    sum = min(sum, getSum(i - mid + 1, j - mid + 1, i, j));
                }
            }
            if(sum <= threshold) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};