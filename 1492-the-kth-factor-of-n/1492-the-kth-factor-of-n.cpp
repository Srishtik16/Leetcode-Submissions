class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                if(n / i == i) {
                    cnt++;
                }
                else {
                    cnt += 2;
                }
            }
        }
        if(cnt < k) {
            return -1;
        }
        int ptr = 0;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                ptr++;
                if(ptr == k) {
                    return i;
                }
                if(cnt - ptr + 1 == k) {
                    return n / i;
                }
            }
        }
        return -1;
    }
};