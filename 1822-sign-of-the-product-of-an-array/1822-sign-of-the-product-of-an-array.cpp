class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(auto x: nums) {
            if(x == 0) {
                ans = 0;
                break;
            }
            ans *= (abs(x) / x);
        }
        return ans;
    }
};