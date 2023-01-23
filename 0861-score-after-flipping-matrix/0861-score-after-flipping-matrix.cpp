class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < m; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int best = 0;
        vector<int> pref(m);
        for(int i = 0; i < m; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += grid[j][i];
            }
            pref[i] = sum;
        }
        for(int mask = 0; mask < (1LL << m); mask++) {
            int score = 0;
            for(int i = 0; i < m; i++) {
                if((1LL << i) & mask) {
                    score += ((1LL << (m - i - 1)) * (n - pref[i]));
                }
                else {
                    score += ((1LL << (m - i - 1)) * pref[i]);
                }
            }
            best = max(best, score);
        }
        return best;
    }
};