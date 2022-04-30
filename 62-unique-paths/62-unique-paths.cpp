using ll = unsigned long long;
class Solution {
public:
    int uniquePaths(int rows, int columns) {
        int ptr = 1;
        ll ans = 1;
        for(int i = rows + columns - 2; i >= 1; i--) {
            ans *= i;
            ans /= ptr;
            ptr++;
            if(ptr == min(rows, columns)) {
                break;
            }
        }
        if(ans == 0) {
            ans = 1;
        }
        return (int)ans;
    }
};