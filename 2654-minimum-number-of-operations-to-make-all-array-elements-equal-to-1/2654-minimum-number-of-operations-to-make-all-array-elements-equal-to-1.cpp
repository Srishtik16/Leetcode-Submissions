class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(accumulate(nums.begin(), nums.end(), 0, [&](const int &x, const int &y) {
            return __gcd(x, y);
        }) != 1) {
            return -1;
        }
        int c1 = count(nums.begin(), nums.end(), 1);
        if(c1 > 0) {
            return (int)nums.size() - c1;
        }
        int n = nums.size();
        int dist = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int g = accumulate(nums.begin() + i, nums.begin() + j + 1, 0, [&](const int &x, const int &y) {
            return __gcd(x, y);
                });
                if(g == 1) {
                    dist = min(dist, j - i);
                }
            }
        }
        return dist == INT_MAX ? -1 : n - 1 + dist;
    }
};