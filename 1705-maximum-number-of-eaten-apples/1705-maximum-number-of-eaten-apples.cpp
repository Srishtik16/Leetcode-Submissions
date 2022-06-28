class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;
        for(int i = 0; i < apples.size() || pq.size(); i++) {
            if(i < apples.size()) {
                pq.push({i + days[i], apples[i]});
            }
            while(!pq.empty() && i >= pq.top().first) {
                pq.pop();
            }
            if(pq.empty()) {
                continue;
            }
            auto val = pq.top();
            pq.pop();
            ans++;
            val.second--;
            if(val.second > 0) {
                pq.push(val);
            }
        }
        return ans;
    }
};