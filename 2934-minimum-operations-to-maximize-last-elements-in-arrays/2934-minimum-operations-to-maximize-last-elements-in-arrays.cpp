class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        auto check = [&](vector<int> &a, vector<int> &b) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] <= a.back() && b[i] <= b.back()) {
                    continue;
                }
                if(a[i] <= b.back() && b[i] <= a.back()) {
                    count++;
                    continue;
                }
                return INT_MAX - 1;
            }
            return count;
        };
        int mn = check(nums1, nums2);
        swap(nums1.back(), nums2.back());
        mn = min(mn, check(nums1, nums2) + 1);
        return mn >= INT_MAX - 1 ? -1 : mn;
    }
};