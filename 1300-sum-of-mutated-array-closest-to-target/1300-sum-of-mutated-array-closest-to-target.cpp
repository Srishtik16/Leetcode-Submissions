class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int l = 0, r = *max_element(arr.begin(), arr.end()), ans = INT_MAX;
        auto check = [&](int val) {
            int sum = 0;
            for(auto x: arr) {
                sum += (x <= val ? x : val);
            }
            return sum;
        };
        int res = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            int sum = check(mid);
            if(sum >= target) {
                if(abs(target - sum) <= ans) {
                    ans = abs(target - sum);
                    res = mid;
                }
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        l = 0, r = *max_element(arr.begin(), arr.end());
        while(l <= r) {
            int mid = (l + r) / 2;
            int sum = check(mid);
            if(sum < target) {
                if(abs(target - sum) < ans) {
                    ans = abs(target - sum);
                    res = mid;
                }
                if(abs(target - sum) == ans) {
                    res = min(res, mid);
                }
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return res;
    }
};