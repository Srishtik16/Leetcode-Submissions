class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        for(auto x: roads) {
            deg[x[0]]++;
            deg[x[1]]++;
        }
        vector<pair<int, int>> track;
        for(int i = 0; i < n; i++) {
            track.push_back({deg[i], i});
        }
        sort(track.rbegin(), track.rend());
        int ptr = n;
        map<int, int> m;
        for(auto x: track) {
            m[x.second] = ptr;
            ptr--;
        }
        long long ans = 0;
        for(auto x: roads) {
            ans += m[x[0]] + m[x[1]];
        }
        return ans;
    }
};