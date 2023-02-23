class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {capital[i], profits[i]};
        }
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        int curr = 0;
        for(int i = 0; i < k; i++) {
            while(curr < n && v[curr].first <= w) {
                pq.push(v[curr].second);
                curr++;
            }
            if(pq.empty()) {
                break;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};