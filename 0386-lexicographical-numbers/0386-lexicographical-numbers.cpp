class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        sort(a.begin(), a.end(), [&](const int &x, const int &y) {
            return to_string(x) < to_string(y);
        });
        return a;
    }
};