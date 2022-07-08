class Solution {
public:
    vector<int> houses;
    vector<vector<int>> cost;
    int recurse(int index, int neighbourCount, int prevColor, int target, int dp[][101][21]) {
        if(index == houses.size()) {
            return neighbourCount == target ? 0 : 1e9;
        }
        if(index > houses.size()) {
            return 1e9;
        }
        if(dp[index][neighbourCount][prevColor] != -1) {
            return dp[index][neighbourCount][prevColor];
        }
        int minCost = 1e9;
        if(houses[index]) {
            // already coloured
            int newNeighbourCount = neighbourCount + (houses[index] != prevColor);
            minCost = min(minCost, recurse(index + 1, newNeighbourCount, houses[index], target, dp));
        }
        else {
            // not yet coloured
            for(int col = 0; col < cost[0].size(); col++) {
                int newNeighbourCount = neighbourCount + (col + 1 != prevColor);
                minCost = min(minCost, cost[index][col] + recurse(index + 1, newNeighbourCount, col + 1, target, dp));
            }
        }
        return dp[index][neighbourCount][prevColor] = minCost;
    }
    int minCost(vector<int>& _houses, vector<vector<int>>& _cost, int m, int n, int target) {
        houses = _houses;
        cost = _cost;
        int dp[101][101][21];
        memset(dp, -1, sizeof(dp));
        return recurse(0, 0, 0, target, dp) == 1e9 ? -1 : recurse(0, 0, 0, target, dp);
    }
};