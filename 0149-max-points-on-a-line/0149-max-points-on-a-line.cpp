class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 1;
        for(int i = 0; i < n; i++) {
            map<long double, int> m;
            for(int j = 0; j < n; j++) {
                if(j == i) {
                    continue;
                }
                m[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
            }
            for(auto x: m) {
                ans = max(ans, x.second + 1);
            }
        }
        return ans;
    }
};