class Solution {
public:
    int countLargestGroup(int n) {
        auto digSum = [&](int x) {
            int s = 0;
            while(x > 0) {
                s += x % 10;
                x /= 10;
            }
            return s;
        };
        map<int, int> m;
        for(int i = 1; i <= n; i++) {
            m[digSum(i)]++;
        }
        int mx = 0;
        for(auto x: m) {
            mx = max(mx, x.second);
        }
        int ans = 0;
        for(auto x: m) {
            ans += mx == x.second;
        }
        return ans;
    }
};