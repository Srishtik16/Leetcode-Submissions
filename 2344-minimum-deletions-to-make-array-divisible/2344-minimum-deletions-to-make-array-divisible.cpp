class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = accumulate(numsDivide.begin(), numsDivide.end(), 0, [&](const int &x, const int &y){
           return __gcd(x, y); 
        });
        vector<int> bad;
        int mn = INT_MAX, ans = 0;
        for(auto x: nums) {
            if(g % x == 0) {
                mn = min(mn, x);
                continue;
            }
            bad.push_back(x);
        }
        for(auto x: bad) {
            if(x < mn) {
                ans++;
            }
        }
        return ans == nums.size() ? -1 : ans;
    }
};