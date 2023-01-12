class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> base;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = n - 1; j >= 0; j--) {
                sum += grid[i][j];
                if(sum == 1) {
                    base.push_back(n - j - 1);
                    break;
                }
            }
            if(sum == 0) {
                base.push_back(n);
            }
        }
        int moves = 0;
        for(int i = 0; i < n; i++) {
            if(base[i] < n - i - 1) {
                int j = i;
                while(j < n && base[j] < n - i - 1) {
                    j++;
                }
                if(j == n) {
                    return -1;
                }
                while(i < j) {
                    swap(base[j], base[j - 1]);
                    moves++;
                    j--;
                }
            }
        }
        return moves;
    }
};