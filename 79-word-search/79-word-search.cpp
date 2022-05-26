class Solution {
public:
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, int index, string word, string &aux, int x, int y) {
        if(index == (int)word.size()) {
            return true;
        }
        if(x < 0 || y < 0 || x >= (int)board.size() || y >= (int)board[0].size()) {
            return false;
        }
        if(vis[x][y]) {
            return false;
        }
        aux += board[x][y];
        if(word[index] != aux.back()) {
            return false;
        }
        vis[x][y] = true;
        bool ans = false;
        ans |= dfs(board, vis, index + 1, word, aux, x + 1, y);
        ans |= dfs(board, vis, index + 1, word, aux, x - 1, y);
        ans |= dfs(board, vis, index + 1, word, aux, x, y + 1);
        ans |= dfs(board, vis, index + 1, word, aux, x, y - 1);
        vis[x][y] = false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        bool ok = false;
        string aux = "";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    ok |= dfs(board, vis, 0, word, aux, i, j);
                    if(ok) {
                        return true;
                    }
                }
            }
        }
        return ok;
    }
};