class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n, ans = -1;
        vector<bool> pref(n + 1, false), suff(n + 1, false);
        pref[0] = true;
        pref[1] = true;
        suff[n] = true;
        suff[n - 1] = true;
        for(int i = 2; i <= n; i++) {
            pref[i] = pref[i - 1] & (a[i - 2] <= a[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] & (a[i] <= a[i + 1]);
        }
        while(l <= r) {
            int mid = (l + r) / 2;
            int left = 0, right = mid - 1;
            bool ok = false;
            if(left > right) {
                ok = pref.back();
            }
            while(left <= right && right < n) {
                if(left == 0) {
                    ok |= suff[right + 1];
                }
                else if(right == n - 1) {
                    ok |= pref[left];
                }
                else {
                    if(a[left - 1] <= a[right + 1] && pref[left] && suff[right + 1]) {
                        ok = true;
                    }
                }
                if(ok) {
                    break;
                }
                left++;
                right++;
            }
            if(ok) {
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