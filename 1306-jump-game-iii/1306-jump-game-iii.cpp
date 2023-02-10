class Solution {
public:
    bool ok;
    void dfs(int node, vector<int> &arr, vector<bool> &vis) {
        if(arr[node] == 0) {
            ok = true;
            return;
        }
        vis[node] = true;
        if(node + arr[node] < (int)arr.size() && !vis[node + arr[node]]) {
            dfs(node + arr[node], arr, vis);
        }
        if(node - arr[node] >= 0 && !vis[node - arr[node]]) {
            dfs(node - arr[node], arr, vis);
        }
    }
    bool canReach(vector<int>& arr, int start) {
        ok = false;
        int n = arr.size();
        vector<bool> vis(n, false);
        dfs(start, arr, vis);
        return ok;
    }
};