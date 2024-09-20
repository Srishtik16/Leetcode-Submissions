class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int m = ranges.size();
        map<int, int> bestRight;
        for(int i = 0; i < m; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            bestRight[left] = max(bestRight[left], right);
        }
        int curr = bestRight[0];
        int nextBest = 0;
        int ans = 1;
        for(int i = 1; i <= n && curr < n; i++) {
            if(i > curr) {
                return -1; // can't reach this i
            }
            else if(i == curr) {
                nextBest = max(nextBest, bestRight[i]);
                curr = nextBest;
                nextBest = 0;
                ans++;
            }
            else {
                nextBest = max(nextBest, bestRight[i]);
            }
        }
        return ans;
    }
};