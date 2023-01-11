class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // Find appropriate row with binary search, then binary search
        // on that row to get element if exists
        int l = 0, r = n - 1, ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(matrix[mid][m - 1] >= target) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if(ans == -1) {
            return false;
        }
        l = 0, r = m - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(matrix[ans][mid] == target) {
                return true;
            }
            else if(matrix[ans][mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return false;
    }
};