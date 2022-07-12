class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> vec;
        for(auto x: intervals) {
            vec.push_back({x[0], 1});
            vec.push_back({x[1], -1});
        }
        sort(vec.begin(), vec.end());
        int ans = 0, rooms = 0;
        for(auto x: vec) {
            rooms += x.second;
            ans = max(ans, rooms);
        }
        return ans;
    }
};