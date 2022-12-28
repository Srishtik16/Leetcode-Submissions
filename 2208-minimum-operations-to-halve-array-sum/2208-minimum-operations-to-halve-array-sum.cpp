class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<long double> pq;
        for(auto x: nums) {
            pq.push(x);
        }
        long double ans = accumulate(nums.begin(), nums.end(), 0.0);
        long double sum = 0;
        int ops = 0;
        while(!pq.empty()) {
            long double val = pq.top();
            pq.pop();
            long double rem = val / 2.0;
            val -= rem;
            sum += rem;
            ops++;
            if(sum * 2 * 1000 >= ans * 1000) {
                break;
            }
            if(val > 1) {
                pq.push(val);
            }
        }
        return ops;
    }
};