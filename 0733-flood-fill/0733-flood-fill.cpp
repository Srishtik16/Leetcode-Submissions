class Solution {
public:
    void dfs(int x, int y, int prev, int col, vector<vector<bool>> &vis, vector<vector<int>> &grid) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || vis[x][y] || grid[x][y] != prev) {
            return;
        }
        vis[x][y] = true;
        grid[x][y] = col;
        dfs(x + 1, y, prev, col, vis, grid);
        dfs(x - 1, y, prev, col, vis, grid);
        dfs(x, y + 1, prev, col, vis, grid);
        dfs(x, y - 1, prev, col, vis, grid);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int curr = image[sr][sc];
        dfs(sr, sc, curr, color, vis, image);
        return image;
    }
};