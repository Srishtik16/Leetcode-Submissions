class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {position[i], speed[i]};
        }
        sort(a.begin(), a.end());
        auto compare = [&](int i, int j) {
            int p1 = a[i].first;
            int p2 = a[j].first;
            int s1 = a[i].second;
            int s2 = a[j].second;
            int t1 = (target - p1) * s2;
            int t2 = (target - p2) * s1;
            return t1 <= t2;
        };
        vector<long double> time(n);
        for(int i = 0; i < n; i++) {
            time[i] = 1.0 * (target - a[i].first) / a[i].second;
        }
        stack<long double> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && s.top() <= time[i]) {
                s.pop();
            }
            s.push(time[i]);
        }
        return s.size();
    }
};