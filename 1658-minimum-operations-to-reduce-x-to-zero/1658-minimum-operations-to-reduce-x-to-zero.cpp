class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> suff(n, 0);
        suff[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + nums[i];
        }
        int moves = INT_MAX, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int l = i + 1, r = n - 1, ans = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(suff[mid] >= x - sum) {
                    ans = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            if(ans == -1) {
                continue;
            }
            if(suff[ans] != x - sum) {
                continue;
            }
            moves = min(moves, i + 1 + (n - 1 - ans + 1));
        }
        sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum == x) {
                moves = min(moves, i + 1);
            }
        }
        for(int i = 0; i < n; i++) {
            if(suff[i] == x) {
                moves = min(moves, n - 1 - i + 1);
            }
        }
        if(moves == INT_MAX) {
            moves = -1;
        }
        return moves;
    }
};