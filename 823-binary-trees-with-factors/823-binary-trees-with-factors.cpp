const int MOD = 1e9 + 7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<long long> dp(n, 1);
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[a[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j || a[i] <= a[j]) {
                    continue;
                }
                if(a[i] % a[j] == 0) {
                    int right = j;
                    int left = a[i] / a[j];
                    if(m.find(left) == m.end()) {
                        continue;
                    }
                    dp[i] += (dp[m[left]] * 1LL * dp[right]);
                    dp[i] %= MOD;
                }
            }
        }
        long long ans = 0;
        for(auto x: dp) {
            ans += x;
            ans %= MOD;
        }
        return ans;
    }
};