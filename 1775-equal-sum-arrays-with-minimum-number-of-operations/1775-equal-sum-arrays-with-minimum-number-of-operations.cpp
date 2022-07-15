class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(min(nums1.size(), nums2.size()) * 6 < max(nums1.size(), nums2.size())) {
            return -1;
        }
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if(sum1 > sum2) {
            swap(nums1, nums2);
        }
        priority_queue<int, vector<int>, greater<int>> pq1(nums1.begin(), nums1.end());
        priority_queue<int> pq2(nums2.begin(), nums2.end());
        int moves = 0;
        int diff = abs(sum1 - sum2);
        while(diff > 0) {
            moves++;
            if(pq1.empty() || (!pq2.empty() && pq2.top() - 1 > 6 - pq1.top())) {
                diff -= pq2.top() - 1;
                pq2.pop();
            }
            else {
                diff -= 6 - pq1.top();
                pq1.pop();
            }
        }
        return moves;
    }
};