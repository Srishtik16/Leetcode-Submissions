class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            arr[i] %= k;
            arr[i] += k;
            arr[i] %= k;
        }
        sort(arr.begin(), arr.end());
        int zeroes = count(arr.begin(), arr.end(), 0);
        if(zeroes & 1) {
            return false;
        }
        int i = 0;
        for(; i < n; i++) {
            if(arr[i] != 0) {
                break;
            }
        }
        int j = n - 1;
        while(i < j) {
            if(arr[i] + arr[j] == k) {
                i++;
                j--;
                continue;
            }
            return false;
        }
        return true;
    }
};