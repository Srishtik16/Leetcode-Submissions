class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        // kth smallest in m * n matrix comes from merging kth smallest in (m - 1) * n matrix with the last row and trimming to k elements
        // dp[i] = {k smallest sums in using 1st i rows}
        // dp[0] = mat[0][k elements]
        // dp[i] = dp[i - 1] X mat[i] taking k smallest elements (X is cartesian product sum or cross product)
        // ans = dp.back()
        int n = mat.size();
        int m = mat[0].size();
        vector<int> dp;
        for(int i = 0; i < min(m, k); i++) {
            dp.push_back(mat[0][i]);
        }
        for(int i = 1; i < n; i++) {
            vector<int> new_dp;
            multiset<int> ms;
            for(int j = 0; j < m; j++) {
                for(auto x: dp) {
                    if(ms.size() >= k) {
                        if(*ms.rbegin() > x + mat[i][j]) {
                            ms.erase(ms.find(*ms.rbegin()));
                            ms.insert(x + mat[i][j]);
                        }
                    }
                    else {
                        ms.insert(x + mat[i][j]);
                    }
                }
            }
            for(auto x: ms) {
                new_dp.push_back(x);
            }
            swap(dp, new_dp);
        }
        return dp.back();
    }
};