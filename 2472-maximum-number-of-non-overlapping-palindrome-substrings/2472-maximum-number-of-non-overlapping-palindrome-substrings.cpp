class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
            if(i + 1 < n) {
                dp[i][i + 1] = s[i] == s[i + 1];
            }
        }
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < n - 1; i++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i][j] | dp[i + 1][j - 1];
                }
            }
        }
        vector<pair<int, int>> ranges;
        for(int i = 0; i < n; i++) {
            for(int j = i + k - 1; j < n; j++) {
                if(dp[i][j]) {
                    ranges.push_back({i, j});
                }
            }
        }
        if(ranges.size() <= 1) {
            return ranges.size();
        }
        sort(ranges.begin(), ranges.end(), [&](const auto &x, const auto &y) {
            return x.second < y.second;
        });
        auto overlap = [&](pair<int, int> &x, pair<int, int> &y) {
            return max(x.first, y.first) <= min(x.second, y.second);
        };
        pair<int, int> curr = ranges[0];
        int i = 1, ans = 1;
        n = ranges.size();
        while(i < n) {
            if(overlap(curr, ranges[i])) {
                i++;
            }
            else {
                ans++;
                curr = ranges[i];
                i++;
            }
        }
        return ans;
    }
};