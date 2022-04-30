class Solution {
public:
    int merge(vector<int> &nums, int start, int mid, int end) {
        int cnt = 0, j = mid + 1;
        for(int i = start; i <= mid; i++) {
            while(j <= end && nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }
        vector<int> aux;
        int left = start, right = mid + 1;
        while(left <= mid && right <= end) {
            if(nums[left] <= nums[right]) {
                aux.push_back(nums[left]);
                left++;
            }
            else {
                aux.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid) {
            aux.push_back(nums[left]);
            left++;
        }
        while(right <= end) {
            aux.push_back(nums[right]);
            right++;
        }
        for(int i = start; i <= end; i++) {
            nums[i] = aux[i - start];
        }
        return cnt;
    }
    int mergeSort(vector<int> &nums, int start, int end) {
        if(start >= end) {
            return 0;
        }
        int inv = 0;
        int mid = (start + end) / 2;
        inv += mergeSort(nums, start, mid);
        inv += mergeSort(nums, mid + 1, end);
        inv += merge(nums, start, mid, end);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, (int)nums.size() - 1);
    }
};