class Solution {
public:
    int getKth(int lo, int hi, int k) {
        auto getMoves = [&](int n) {
            int moves = 0;
            while(n != 1) {
                if(n & 1) {
                    n = 3 * n + 1;
                }
                else {
                    n /= 2;
                }
                moves++;
            }
            return moves;
        };
        vector<int> a;
        for(int i = lo; i <= hi; i++) {
            a.push_back(i);
        }
        sort(a.begin(), a.end(), [&](const int &x, const int &y) {
            int m1 = getMoves(x);
            int m2 = getMoves(y);
            if(m1 == m2) {
                return x < y;
            }
            return m1 < m2;
        });
        return a[k - 1];
    }
};