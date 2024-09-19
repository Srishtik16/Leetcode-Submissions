class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int right = destination[1];
        int down = destination[0];
        vector<vector<int>> dp(right + down + 1, vector<int>(right + down + 1));
        for(int i = 0; i <= right + down; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= right + down; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        string ans = "";
        while(right > 0 && down > 0) {
            // try to place a H at current first position
            int ways = dp[right + down - 1][right - 1];
            if(ways >= k) {
                ans += 'H';
                right--;
            }
            else {
                ans += 'V';
                down--;
                k -= ways;
            }
            
        }
        ans += string(right, 'H') + string(down, 'V');
        return ans;
    }
};