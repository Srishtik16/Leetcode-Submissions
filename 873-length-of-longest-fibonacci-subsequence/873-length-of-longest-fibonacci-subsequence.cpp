class Solution {
public:
    int lenLongestFibSubseq(vector<int>& a) {
        int n = a.size();
        map<int, int> dp;
        for(int i = 2; i < n; i++) {
            for(int j = 1; j < i; j++) {
                int diff = a[i] - a[j];
                int ind = lower_bound(a.begin(), a.begin() + j, diff) - a.begin();
                if(ind < j && a[ind] == diff) {
                    int len = 0;
                    if(dp.find(ind * n + j) == dp.end()) {
                        len = 3;
                    }
                    else {
                        len = dp[ind * n + j] + 1;
                    }
                    dp[j * n + i] = len;
                }
            }
        }
        int ans = 0;
        for(auto x: dp) {
            ans = max(ans, x.second);
        }
        return ans;
    }
};