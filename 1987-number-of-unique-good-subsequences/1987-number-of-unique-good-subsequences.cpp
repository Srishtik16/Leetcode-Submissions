class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int ones = 0, zeroes = 0;
        bool ok = false;
        const int MOD = 1e9 + 7;
        for(char c: binary) {
            if(c == '1') {
                ones = (ones + zeroes + 1) % MOD;
            }
            else {
                ok = true;
                zeroes = (ones + zeroes) % MOD;
            }
        }
        return (ones + zeroes + ok) % MOD;
    }
};

// dp[i] = number of subsequences ending at i
// if(si == 1) -> 

// 1101
// 1
// 11
// 110
// 1101
// 10
// 11 (bad)
// 11 (bad)