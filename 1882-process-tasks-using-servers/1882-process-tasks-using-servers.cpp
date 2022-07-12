class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        multiset<vector<int>> busy, idle;
        for(int i = 0; i < n; i++) {
            idle.insert({servers[i], i});
        }
        vector<int> ans(m);
        int time = 0;
        for(int i = 0; i < m; i++) {
            time = max(time, i);
            if(idle.empty()) {
                time = max(time, (*busy.begin())[0]); 
            }
            while(!busy.empty() && (*busy.begin())[0] <= time) {
                auto it = *busy.begin();
                idle.insert({servers[it[1]], it[1]});
                busy.erase(busy.begin());
            }
            auto it = *idle.begin();
            busy.insert({time + tasks[i], it[1]});
            ans[i] = it[1];
            idle.erase(idle.begin());
        }
        return ans;
    }
};