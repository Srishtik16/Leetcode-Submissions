class Solution {
public:
    vector<vector<char>> board;
    void dfs(int i, int j) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.') {
            return;
        }
        board[i][j] = '.';
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }
    int countBattleships(vector<vector<char>>& _board) {
        board = _board;
        int ans = 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'X') {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};