class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int MOD = 1e9 + 7;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mxHeight = 0, mxWidth = 0;
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        for(int i = 1; i < n; i++) {
            mxHeight = max(mxHeight, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for(int i = 1; i < m; i++) {
            mxWidth = max(mxWidth, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return (mxHeight * 1LL * mxWidth) % MOD;
    }
};