class Solution {
public:
    int findComplement(int num) {
        auto toBin = [&](int n) {
            string ans = "";
            while(n > 0) {
                ans += (n % 2 == 0 ? '0' : '1');
                n /= 2;
            }
            return ans;
        };
        auto toDec = [&](string s) {
            int pw = 0;
            int ans = 0;
            for(char c: s) {
                ans += (1LL << pw++) * (1 - (c - '0'));
            }
            return ans;
        };
        return toDec(toBin(num));
    }
};