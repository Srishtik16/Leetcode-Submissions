class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> suff(n);
        suff[n - 1] = values[n - 1] - n + 1;
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], values[i] - i);
        }
        int score = 0;
        for(int i = 0; i < n - 1; i++) {
            score = max(score, values[i] + i + suff[i + 1]);
        }
        return score;
    }
};