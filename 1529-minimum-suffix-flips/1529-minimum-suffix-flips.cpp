class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        bool parity = false; // false -> even, true -> odd
        int moves = 0;
        for(int i = 0; i < n; i++) {
            if(parity) {
                if(target[i] == '0') {
                    parity ^= 1;
                    moves++;
                } 
            }
            else {
                if(target[i] == '1') {
                    parity ^= 1;
                    moves++;
                }
            }
        }
        return moves;
    }
};