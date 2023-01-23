class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n + 1), suff(n + 1);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + (nums[i - 1] == 0);
        }
        for(int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + (nums[i] == 1);
        }
        int best = 0;
        for(int i = 0; i <= n; i++) {
            best = max(best, pref[i] + suff[i]);
        }
        vector<int> indices;
        for(int i = 0; i <= n; i++) {
            if(best == pref[i] + suff[i]) {
                indices.push_back(i);
            }
        }
        return indices;
    }
};