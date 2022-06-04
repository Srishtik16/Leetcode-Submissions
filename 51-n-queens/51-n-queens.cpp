class Solution {
public:
    bool canPlace(int n, vector<vector<int>> &board, int i, int j) {
        for(int k = 0; k < i; k++) {
            if(board[k][j] == 1) {
                return false;
            }
        }
        int x = i, y = j;
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 1) {
                return false;
            }
            x--;
            y--;
        }
        x = i, y = j;
        while(x >= 0 && y < n) {
            if(board[x][y] == 1) {
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    bool recurse(int n, vector<vector<string>> &ans, vector<vector<int>> &board, int i) {
        if(i == n) {
            vector<string> aux;
            for(int i = 0; i < n; i++) {
                string s = "";
                for(int j = 0; j < n; j++) {
                    if(board[i][j] == 1) {
                        s += 'Q';
                    }
                    else {
                        s += '.';
                    }
                }
                aux.push_back(s);
            }
            ans.push_back(aux);
        }
        for(int j = 0; j < n; j++) {
            if(canPlace(n, board, i, j)) {
                board[i][j] = 1;
                bool ok = recurse(n, ans, board, i + 1);
                if(ok) {
                    return true;
                }
                board[i][j] = 0;
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(20, vector<int>(20, 0));
        vector<vector<string>> ans;
        recurse(n, ans, board, 0);
        return ans;
    }
};