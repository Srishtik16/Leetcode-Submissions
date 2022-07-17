class Solution {
public:
    int maximumSum(vector<int>& nums) {
        auto digitSum = [&](int x) {
            int sum = 0;
            while(x > 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };
        map<int, int> m;
        int ans = -1;
        for(auto x: nums) {
            int ds = digitSum(x);
            if(m.find(ds) != m.end()) {
                ans = max(ans, m[ds] + x);
            }
            m[ds] = max(m[ds], x);
        }
        return ans;
    }
};