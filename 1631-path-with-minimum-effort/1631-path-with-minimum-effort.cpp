class Solution {
public:
    map<pair<int, int>, int> d;
    int djikstra(pair<int, int> src, pair<int, int> dest, vector<vector<int>> &a) {
        set<pair<int, pair<int, int>>> s;
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < a[0].size(); j++) {
                d[{i, j}] = INT_MAX;
            }
        }
        auto isValid = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < a.size() && j < a[0].size();
        };
        d[{0, 0}] = 0;
        s.insert({0, {0, 0}});
        while(!s.empty()) {
            auto f = *s.begin();
            s.erase(f);
            pair<int, int> u = f.second;
            int i = u.first;
            int j = u.second;
            if(isValid(i + 1, j)) {
                if(max(d[u], abs(a[i][j] - a[i + 1][j])) < d[{i + 1, j}]) {
                    d[{i + 1, j}] = max(d[u], abs(a[i][j] - a[i + 1][j]));
                    s.insert({d[{i + 1, j}], {i + 1, j}});
                }
            }
            if(isValid(i - 1, j)) {
                if(max(d[u], abs(a[i][j] - a[i - 1][j])) < d[{i - 1, j}]) {
                    d[{i - 1, j}] = max(d[u], abs(a[i][j] - a[i - 1][j]));
                    s.insert({d[{i - 1, j}], {i - 1, j}});
                }
            }
            if(isValid(i, j + 1)) {
                if(max(d[u], abs(a[i][j] - a[i][j + 1])) < d[{i, j + 1}]) {
                    d[{i, j + 1}] = max(d[u], abs(a[i][j] - a[i][j + 1]));
                    s.insert({d[{i, j + 1}], {i, j + 1}});
                }
            }
            if(isValid(i, j - 1)) {
                if(max(d[u], abs(a[i][j] - a[i][j - 1])) < d[{i, j - 1}]) {
                    d[{i, j - 1}] = max(d[u], abs(a[i][j] - a[i][j - 1]));
                    s.insert({d[{i, j - 1}], {i, j - 1}});
                }
            }
        }
        return d[dest];
    }
    int minimumEffortPath(vector<vector<int>> &a) {
        int n = a.size();
        int m = a[0].size();
        pair<int, int> src = {0, 0};
        pair<int, int> dest = {n - 1, m - 1};
        int ans = djikstra(src, dest, a);
        return ans;
    }
};