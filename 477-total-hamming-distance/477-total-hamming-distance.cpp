class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        map<int, int> m;
        for(auto x: nums) {
            for(int i = 0; i <= 30; i++) {
                if(x & (1 << i)) {
                    m[i]++;
                }
            }
        }
        for(int i = 0; i <= 30; i++) {
            ans += m[i] * (n - m[i]);
        }
        return ans;
    }
};