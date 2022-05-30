class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {ages[i], scores[i]};
        }
        sort(a.begin(), a.end());
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++) {
            dp[i] = a[i].second;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(a[i].first >= a[j].first && a[i].second >= a[j].second) {
                    dp[i] = max(dp[i], dp[j] + a[i].second);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};