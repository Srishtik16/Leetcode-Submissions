class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        vector<int> fac(n + 1);
        fac[0] = 1;
        for(int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i;
        }
        k--;
        string ans = "";
        while(true) {
            int fact = fac[a.size() - 1];
            ans += to_string(a[k / fact]);
            a.erase(a.begin() + k / fact);
            if(a.empty()) {
                break;
            }
            k %= fact;
        }
        return ans;
    }
};