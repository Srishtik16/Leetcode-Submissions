class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        for(auto x: nums) {
            m[x]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto x: m) {
            if(pq.size() < k) {
                pq.push({m[x.first], x.first});
            }
            else {
                if(pq.top().first < m[x.first]) {
                    pq.pop();
                    pq.push({m[x.first], x.first});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};