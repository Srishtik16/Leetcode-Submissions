class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n = matrix.size();
        int m = matrix[0].size();
        int l = -1e9, r = 1e9, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            int i = n - 1, j = 0;
            int cnt = 0;
            while(i >= 0 && j < m) {
                if(matrix[i][j] > mid) {
                    i--;
                }
                else {
                    cnt += (i + 1);
                    j++;
                }
            }
            if(cnt >= k) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};