const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        auto isValid = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == 1;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < 4; k++) {
                    ans += !isValid(i + dx[k], j + dy[k]) && grid[i][j] == 1;
                }
            }
        }
        return ans;
    }
};