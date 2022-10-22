class Solution {
public:
    int solve(string answerKey, int k, char c) {
        int n = answerKey.size();
        vector<int> prefT(n, 0);
        prefT[0] = answerKey[0] == c;
        for(int i = 1; i < n; i++) {
            prefT[i] = prefT[i - 1] + (answerKey[i] == c);
        }
        auto range = [&](int l, int r, bool which) {
            if(l < 0 || r >= n || l > r) {
                return -1;
            }
            return prefT[r] - (l > 0 ? prefT[l - 1] : 0);
        };
        int l = 1, r = n, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            bool ok = false;
            for(int i = 0; i < n; i++) {
                if(range(i, i + mid - 1, true) != -1) {
                    int tc = range(i, i + mid - 1, true);
                    if(mid - tc <= k) {
                        ok = true;
                        break;
                    }
                }
            }
            if(ok) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(char c = 'A'; c <= 'Z'; c++) {
            ans = max(ans, solve(s, k, c));
        }
        return ans;
    }
};