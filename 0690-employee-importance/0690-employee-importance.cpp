/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    map<int, int> dp;
    map<int, Employee*> track;
    void dfs(Employee* node, map<int, bool> &vis) {
        vis[node -> id] = true;
        dp[node -> id] = node -> importance;
        for(auto x: node -> subordinates) {
            if(!vis[x]) {
                dfs(track[x], vis);
                dp[node -> id] += dp[x];
            }
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        map<int, bool> vis;
        for(auto employee: employees) {
            track[employee -> id] = employee;
        }
        dfs(track[id], vis);
        return dp[id];
    }
};