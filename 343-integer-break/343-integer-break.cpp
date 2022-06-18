class Solution {
public:
    int integerBreak(int n) {
        int ans = 0;
        for(int i = 1; i < n; i++) {
            int val = 0;
            if(n / i - 1 != 0) {
                val = powl(i, ((n / i) - 1)) * (n % i + i);
                cout << val << " ";
                ans = max(ans, val);
            }
            val = powl(i, ((n / i))) * (n % i);
            ans = max(ans, val);
            cout << val << endl;
        }
        return ans; 
    }
};