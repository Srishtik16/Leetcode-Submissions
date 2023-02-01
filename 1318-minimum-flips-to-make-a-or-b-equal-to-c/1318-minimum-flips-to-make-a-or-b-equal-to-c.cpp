class Solution {
public:
    int minFlips(int a, int b, int c) {
        int moves = 0;
        for(int i = 0; i <= 30; i++) {
            if((1LL << i) & c) {
                moves += (((1LL << i) & a) == 0) && (((1LL << i) & b) == 0);
            }
            else {
                moves += (((1LL << i) & a) > 0);
                moves += (((1LL << i) & b) > 0);
            }
        }
        return moves;
    }
};