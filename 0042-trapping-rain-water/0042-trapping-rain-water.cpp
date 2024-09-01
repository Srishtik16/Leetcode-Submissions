class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pref(n), suff(n);
        pref[0] = height[0], suff[n - 1] = height[n - 1];
        for(int i = 1, j = n - 2; i < n, j >= 0; i++, j--) {
            pref[i] = max(pref[i - 1], height[i]);
            suff[j] = max(suff[j + 1], height[j]);
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            if(min(pref[i - 1], suff[i + 1]) <= height[i]) {
                continue;
            }
            ans += abs(height[i] - min(pref[i - 1], suff[i + 1]));
        }
        return ans;
    }
};