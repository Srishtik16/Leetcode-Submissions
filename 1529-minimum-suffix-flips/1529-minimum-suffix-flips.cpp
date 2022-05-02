class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string a(n, '0');
        int par = 0, moves = 0;
        for(int i = 0; i < n; i++) {
            if(par == 0) {
                if(s[i] != '0') {
                    moves++;
                    par ^= 1;
                }
            }
            else {
                if(s[i] == '0') {
                    moves++;
                    par ^= 1;
                }
            }
        }
        return moves;
    }
};