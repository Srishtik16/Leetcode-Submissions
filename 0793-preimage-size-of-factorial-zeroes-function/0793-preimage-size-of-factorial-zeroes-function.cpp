class Solution {
public:
    int preimageSizeFZF(int k) {
        auto check = [&](long long n) {
            long long pw = 5;
            long long ans = 0;
            while(n / pw > 0) {
                ans += (n / pw);
                pw *= 5;
            }
            return ans;
        };
        auto search = [&](int k) {
            long long l = 0, r = 1e15, ans = -1;
            while(l <= r) {
                long long mid = (l + r) / 2;
                if(check(mid) >= k) {
                    ans = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            return ans;
        };
        long long left = search(k);
        if(check(left) != k) {
            return 0;
        }
        long long right = search(k + 1);
        return right - left;
    }
};