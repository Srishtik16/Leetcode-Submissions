class Solution {
public:
    vector<vector<pair<int, int>>> vec;
    int djikstra(int node)
    {
        vector<int> dist((int)vec.size(), 1e9);
        dist[node] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, node});
        while(!pq.empty())
        {
            int v = pq.top().second;
            int d_v = pq.top().first;
            pq.pop();
            if(d_v != dist[v])
            continue;
            for(auto x: vec[v])
            {
                int u = x.first;
                int len = x.second;
                if(len < dist[u])
                {
                    dist[u] = len;
                    pq.push({dist[u], u});
                }
            }
        }
        int ans = 1e9;
        for(int i = 1; i < (int)vec.size(); i++) {
            ans = min(ans, dist[i]);
        }
        return ans == 1e9 ? -1 : ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vec.clear();
        vec.resize(n);
        for(auto &x: roads) {
            int u = x[0], v = x[1], wt = x[2];
            vec[u - 1].push_back({v - 1, wt});
            vec[v - 1].push_back({u - 1, wt});
        }
        return djikstra(0); 
    }
};