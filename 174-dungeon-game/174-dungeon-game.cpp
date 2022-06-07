class Solution {
public:
    int recurse(int i, int j, vector<vector<int>> &dungeon, vector<vector<int>> &dp) {
        if(i < 0 || j < 0 || i >= dungeon.size() || j >= dungeon[0].size()) {
            return INT_MAX;
        }
        if(i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
            return dungeon[i][j] <= 0 ? -dungeon[i][j] + 1 : 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int right = recurse(i, j + 1, dungeon, dp);
        int down = recurse(i + 1, j, dungeon, dp);
        dp[i][j] = min(right, down) - dungeon[i][j];
        dp[i][j] = dp[i][j] <= 0 ? 1 : dp[i][j];
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return recurse(0, 0, dungeon, dp);
    }
};