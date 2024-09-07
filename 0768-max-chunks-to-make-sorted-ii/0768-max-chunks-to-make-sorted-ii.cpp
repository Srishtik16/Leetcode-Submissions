class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> sarr = arr;
        sort(sarr.begin(), sarr.end());
        long long chunks = 0, sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++) {
            sum1 += sarr[i];
            sum2 += arr[i];
            chunks += (sum1 == sum2);
        }
        return chunks;
    }
};