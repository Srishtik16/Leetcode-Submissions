class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp1(n, INT_MAX), dp2(n, INT_MAX);
        map<int, int> m;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum == target) {
                dp1[i] = i + 1;
            }
            if(m.find(sum - target) != m.end()) {
                dp1[i] = min(dp1[i], i - m[sum - target]);
            }
            if(i > 0) {
                dp1[i] = min(dp1[i], dp1[i - 1]);
            }
            m[sum] = i;
        }
        m.clear();
        sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            if(sum == target) {
                dp2[i] = n - i;
            }
            if(m.find(sum - target) != m.end()) {
                dp2[i] = min(dp2[i], m[sum - target] - i);
            }
            if(i < n - 1) {
                dp2[i] = min(dp2[i], dp2[i + 1]);
            }
            m[sum] = i;
        }
        long long ans = INT_MAX;
        for(int i = 1; i < n; i++) {
            ans = min(ans, (long long)dp1[i - 1] + dp2[i]);
        }
        return ans >= INT_MAX ? -1 : ans;
    }
};