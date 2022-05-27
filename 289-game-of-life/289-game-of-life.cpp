class Solution {
public:
    const vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> copy = board;
        auto isValid = [&](int x, int y) {
            return (x >= 0 && y >= 0 && x < n && y < m);
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cnt = 0;
                for(auto x: dir) {
                    if(isValid(i + x.first, j + x.second)) {
                        cnt += board[i + x.first][j + x.second] == 1;
                    }
                }
                if(board[i][j] == 0) {
                    if(cnt == 3) {
                        copy[i][j] = 1;
                    }
                }
                else {
                    if(cnt < 2 || cnt > 3) {
                        copy[i][j] = 0;
                    }
                    else if(cnt == 2 || cnt == 3) {
                        copy[i][j] = 1;
                    }
                }
            }
        }
        board = copy;
    }
};