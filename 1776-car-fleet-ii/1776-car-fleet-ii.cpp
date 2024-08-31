class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        stack<int> s;
        auto getTime = [&](int i, int j) {
            return 1.0 * (cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]);
        };
        vector<double> res(n, -1);
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && (cars[i][1] <= cars[s.top()][1] || getTime(i, s.top()) >= res[s.top()] && res[s.top()] > 0)) {
                s.pop();
            }
            if(!s.empty()) {
                res[i] = getTime(i, s.top());
            }
            s.push(i);
        }
        return res;
    }
};