class Solution {
public:
    string getHint(string secret, string guess) {
        int cntBulls = 0, cntCows = 0, n = secret.size();
        map<char, int> m1, m2;
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) {
                cntBulls++;
            }
            else {
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }
        for(char c = '0'; c <= '9'; c++) {
            cntCows += min(m1[c], m2[c]);
        }
        string ans = to_string(cntBulls);
        ans += "A";
        ans += to_string(cntCows);
        ans += "B";
        return ans;
    }
};