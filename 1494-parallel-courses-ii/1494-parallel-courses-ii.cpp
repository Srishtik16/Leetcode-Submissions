// https://leetcode.com/problems/parallel-courses-ii/discuss/709382/C%2B%2B-O(3n)-bitmask-dynamic-programming-code-with-comments-and-tutorial
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> dependencies(n, 0);
        for(auto &x: relations) {
            int courses = x[1] - 1;
            int prereq = x[0] - 1;
            dependencies[courses] |= (1LL << prereq);
        }
        vector<int> prerequisites(1 << n, 0);
        for(int i = 0; i < (1 << n); i++) {
            for(int j = 0; j < n; j++) {
                if(i & (1LL << j)) {
                    prerequisites[i] |= dependencies[j];
                }
            }
        }
        vector<int> dp(1 << n, n + 1);
        dp[0] = 0;
        for(int i = 1; i < (1LL << n); i++) {
            for(int j = i; j; j = (j - 1) & i) {
                if(__builtin_popcount(j) > k) {
                    continue;
                }
                int alreadyTaken = i ^ ((1LL << n) - 1);
                if((alreadyTaken & prerequisites[j]) == prerequisites[j]) {
                    dp[i] = min(dp[i], dp[i ^ j] + 1);
                }
            }
        }
        return dp.back();
    }
};