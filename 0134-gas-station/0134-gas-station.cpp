class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curr = 0, prev = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(curr < 0) {
                ans = i;
                prev += curr;
                curr = 0;
            }
            curr += gas[i] - cost[i];
        }
        int iter = 2 * n, i = ans + 1;
        int val = 0;
        while(iter--) {
            val += gas[(i - 1 + n) % n] - cost[(i - 1 + n) % n];
            if(val < 0) {
                return -1;
            }
            i = (i + 1) % n;
        }
        return ans;
    }
};