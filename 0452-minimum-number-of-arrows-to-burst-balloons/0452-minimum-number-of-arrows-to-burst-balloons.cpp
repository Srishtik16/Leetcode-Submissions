class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int arrows = 1, minEnd = INT_MAX;
        sort(points.begin(), points.end());
        for(auto &x: points) {
            if(x[0] > minEnd) {
                arrows++;
                minEnd = x[1];
            }
            else {
                minEnd = min(minEnd, x[1]);
            }
        }
        return arrows;
    }
};