class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {position[i], speed[i]};
        }
        sort(a.begin(), a.end());
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