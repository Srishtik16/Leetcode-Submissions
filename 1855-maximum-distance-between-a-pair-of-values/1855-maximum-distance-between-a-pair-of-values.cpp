class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            int l = i + 1, r = m - 1, ans = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(nums2[mid] >= nums1[i]) {
                    ans = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            if(ans != -1) {
                res = max(res, ans - i);
            }
        }
        return res;
    }
};