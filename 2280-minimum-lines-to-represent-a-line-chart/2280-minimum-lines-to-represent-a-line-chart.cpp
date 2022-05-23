class Solution {
public:
    pair<int, int> slopes(vector<int> &x, vector<int> &y) {
        int num = y[1] - x[1];
        int den = y[0] - x[0];
        int g = __gcd(num, den);
        num /= g;
        den /= g;
        return make_pair(num, den);
    }
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if(n == 1) {
            return 0;
        }
        sort(stockPrices.begin(), stockPrices.end());
        int cnt = 1;
        auto slope = slopes(stockPrices[0], stockPrices[1]);
        for(int i = 0; i < n - 1; i++) {
            if(slope != slopes(stockPrices[i], stockPrices[i + 1])) {
                cnt++;
                slope = slopes(stockPrices[i], stockPrices[i + 1]);
            }
        }
        return cnt;
    }
};