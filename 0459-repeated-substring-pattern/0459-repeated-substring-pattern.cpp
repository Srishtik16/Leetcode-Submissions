class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> poss;
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) {
                poss.push_back(i);
            }
        }
        poss.pop_back();
        for(auto x: poss) {
            string st = s.substr(0, x);
            int times = n / x - 1;
            while(times--) {
                st += s.substr(0, x);
            }
            if(st == s) {
                return true;
            }
        }
        return false;
    }
};