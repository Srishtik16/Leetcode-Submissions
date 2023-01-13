class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end()), ans = r;
        auto check = [&](int x) {
            vector<int> a = nums;
            for(auto &ele: a) {
                ele = (ele + x - 1) / x;
            }
            return accumulate(a.begin(), a.end(), 0LL) <= threshold;
        };
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};