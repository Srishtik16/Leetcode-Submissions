using ll = long long;
class Solution {
public:
    void multiply(vector<vector<ll>> &a, vector<vector<ll>> &b) {
        // Computes a *= b
        int r1 = a.size();
        int r2 = b.size();
        int c1 = a[0].size();
        int c2 = b[0].size();
        vector<vector<ll>> c(r1, vector<ll>(c2, 0));
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c2; j++) {
                for(int k = 0; k < r2; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        a = c;
    }
    void expo(vector<vector<ll>> &m, int k) {
        // Computes m^k in O(log k)
        vector<vector<ll>> res(3, vector<ll>(3, 0));
        res[0][0] = res[1][1] = res[2][2] = 1;
        while(k > 0) {
            if(k & 1) {
                multiply(res, m);
            }
            multiply(m, m);
            k /= 2;
        }
        m = res;
    }
    int tribonacci(int n) {
        // Base Cases
        if(n == 0) {
            return 0;
        }
        if(n <= 2) {
            return 1;
        }
        // Base Matrix of 3 X 1 dimension
        vector<vector<ll>> base(3, vector<ll>(1, 0));
        base[0][0] = base[1][0] = 1;
        base[2][0] = 0;
        // Transition Matrix of 3 X 3 dimension
        vector<vector<ll>> m(3, vector<ll>(3, 0));
        m[0][0] = m[0][1] = m[0][2] = m[1][0] = m[2][1] = 1;
        expo(m, n - 2);
        multiply(m, base);
        return m[0][0];
    }
};