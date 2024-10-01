class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        stack<int> st1, st2;
        vector<int> pge(n), nge(n);
        for(int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
            while(!st1.empty() && nums[st1.top()] >= nums[i]) {
                st1.pop();
            }
            while(!st2.empty() && nums[st2.top()] >= nums[j]) {
                st2.pop();
            }
            pge[i] = st1.empty() ? -1 : st1.top();
            nge[j] = st2.empty() ? n : st2.top();
            st1.push(i);
            st2.push(j);
        }
        vector<long long> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        long long best = 0;
        for(int i = 0; i < n; i++) {
            int l = pge[i];
            int r = nge[i];
            long long sum = pref[r - 1] - (l > -1 ? pref[l] : 0);
            best = max(best, sum * 1LL * nums[i]);
        }
        return best % 1'000'000'007;
    }
};