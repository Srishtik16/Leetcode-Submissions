class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m - 1, ans = m;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(matrix[mid][0] > target) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        ans--;
        if(ans < 0) {
            return false;
        }
        cout << ans << endl;
        l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(matrix[ans][mid] == target) {
                return true;
            }
            else if(matrix[ans][mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }
};