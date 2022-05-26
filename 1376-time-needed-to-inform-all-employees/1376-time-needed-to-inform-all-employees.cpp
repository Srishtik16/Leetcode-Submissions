class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> vec[n];
        vector<int> time(n, 0);
        int root = 0;
        for(int i = 0; i < n; i++) {
            if(manager[i] == -1) {
                root = i;
                continue;
            }
            vec[manager[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            time[u.first] = u.second;
            for(auto x: vec[u.first]) {
                q.push({x, u.second + informTime[u.first]});
            }
        }
        return *max_element(time.begin(), time.end());
    }
};