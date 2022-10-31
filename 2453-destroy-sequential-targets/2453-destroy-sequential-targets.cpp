class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int, int> m;
        for(auto x: nums) {
            m[x % space]++;
        }
        int mx = -1;
        for(auto x: m) {
            mx = max(mx, x.second);
        }
        sort(nums.begin(), nums.end());
        for(auto x: nums) {
            if(m[x % space] == mx) {
                return x;
            }
        }
        return -1;
    }
};