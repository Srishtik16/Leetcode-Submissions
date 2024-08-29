class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        // we can have x - prev moves on number x
        int n = target.size();
        int moves = 0, prev = 0;
        for(auto x: target) {
            moves += max(0, x - prev);
            prev = x;
        }
        return moves;
    }
};