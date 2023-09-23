class Solution {
public:
    bool winnerOfGame(string colors) {
        int movesA = 0, movesB = 0, islandA = 0, islandB = 0;
        for(char c: colors) {
            if(c == 'A') {
                islandA++;
                movesB += max(0, islandB - 2);
                islandB = 0;
            }
            else {
                islandB++;
                movesA += max(0, islandA - 2);
                islandA = 0;
            }
        }
        movesA += max(0, islandA - 2);
        movesB += max(0, islandB - 2);
        bool turn = true;
        while(true) {
            if(turn && movesA <= 0) {
                return false;
            }
            else if(!turn && movesB <= 0) {
                return true;
            }
            else if(turn) {
                movesA--;
                turn ^= 1;
            }
            else if(!turn) {
                movesB--;
                turn ^= 1;
            }
        }
        return turn;
    }
};