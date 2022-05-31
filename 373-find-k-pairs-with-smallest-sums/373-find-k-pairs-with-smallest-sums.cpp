class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pq.size() < k) {
                    pq.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                }
                else if(pq.top().first > nums1[i] + nums2[j]) {
                    pq.pop();
                    pq.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                }
                else {
                    break;
                }
            }
        }
        while(!pq.empty()) {
            ans.push_back(vector<int>{pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};