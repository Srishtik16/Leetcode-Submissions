class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto x: piles) {
            pq.push(x);
        }
        int ans = accumulate(piles.begin(), piles.end(), 0);
        while(!pq.empty() && k--) {
            int val = pq.top();
            pq.pop();
            int rem = val / 2;
            val -= rem;
            ans -= rem;
            if(val > 1) {
                pq.push(val);
            }
        }
        return ans;
    }
};