class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> cells(n * n + 1);
        int cellNo = 1;
        bool turn = true;
        for(int i = n - 1; i >= 0; i--) {
            if(turn) {
                for(int j = 0; j < n; j++) {
                    cells[cellNo++] = {i, j};
                }
            }
            else {
                for(int j = n - 1; j >= 0; j--) {
                    cells[cellNo++] = {i, j};
                }
            }
            turn ^= 1;
        }
        vector<int> d(n * n + 1, -1);
        queue<int> q;
        q.push(1);
        d[1] = 0;
        while(!q.empty()) {
            int u =  q.front();
            q.pop();
            for(int i = u + 1; i <= min(n * n, u + 6); i++) {
                int r = cells[i][0];
                int c = cells[i][1];
                int dest = board[r][c] != -1 ? board[r][c] : i;
                if(d[dest] == -1) {
                    d[dest] = d[u] + 1;
                    q.push(dest);
                }
            }
        }
        return d[n * n];
    }
};