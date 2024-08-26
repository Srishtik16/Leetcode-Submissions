class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        int sum = 0;
        const int MOD = 1e9 + 7;
        for(char c: s) {
            count[c - 'a'] = (sum + 1) % MOD;
            sum = accumulate(count.begin(), count.end(), 0, [&](const int &x, const int &y) {
                return (x + y) % MOD;
            });
        }
        return accumulate(count.begin(), count.end(), 0, [&](const int &x, const int &y) {
                return (x + y) % MOD;
            });
    }
};