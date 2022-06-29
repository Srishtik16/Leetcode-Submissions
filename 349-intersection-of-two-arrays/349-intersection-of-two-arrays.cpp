class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> ms1(nums1.begin(), nums1.end()), ms2(nums2.begin(), nums2.end());
        vector<int> ans;
        for(auto x: ms1) {
            if(ms2.find(x) != ms2.end()) {
                ans.push_back(x);
                ms2.erase(x);
            }
        }
        return ans;
    }
};