class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        auto check = [&](int n) {
            string s = to_string(n * n);
            int l = s.size();
            for(int mask = 0; mask < (1LL << l); mask++) {
                string st = "";
                for(int i = 0; i < l; i++) {
                    if((1 << i) & mask) {
                        st += '1';
                    }
                    else {
                        st += '0';
                    }
                }
                string aux = "";
                int score = 0;
                for(int i = 0; i < l; i++) {
                    if(st[i] == '0') {
                        aux += s[i];
                    }
                    else {
                        aux += s[i];
                        score += stoi(aux);
                        aux.clear();
                    }
                }
                score += aux.empty() ? 0 : stoi(aux);
                if(score == n) {
                    return true;
                }
            } 
            return false;
        };
        for(int i = 1; i <= n; i++) {
            if(check(i)) {
                ans += i * i;
            }
        }
        return ans;
    }
};