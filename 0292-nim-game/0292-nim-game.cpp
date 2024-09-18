class Solution {
public:
    bool canWinNim(int n) {
        // from n we go to n - 1, n - 2, n - 3
        // the answer is based on pattern match from dp
        return n % 4 != 0;
    }
};