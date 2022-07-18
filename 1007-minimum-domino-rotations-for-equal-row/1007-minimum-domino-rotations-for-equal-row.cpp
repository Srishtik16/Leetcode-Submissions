class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = INT_MAX;
        for(int i = 1; i <= 6; i++) {
            int moves = 0;
            bool ok = true;
            for(int j = 0; j < n; j++) {
                if(tops[j] == i) {
                    continue;
                }
                else if(bottoms[j] == i) {
                    moves++;
                }
                else {
                    ok = false;
                }
            }
            if(ok) {
                ans = min(ans, moves);
            }
        }
        swap(tops, bottoms);
        for(int i = 1; i <= 6; i++) {
            int moves = 0;
            bool ok = true;
            for(int j = 0; j < n; j++) {
                if(tops[j] == i) {
                    continue;
                }
                else if(bottoms[j] == i) {
                    moves++;
                }
                else {
                    ok = false;
                }
            }
            if(ok) {
                ans = min(ans, moves);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};