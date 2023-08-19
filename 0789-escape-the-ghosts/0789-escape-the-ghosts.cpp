class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> distances;
        auto distance = [&](auto x) {
            return abs(x[0] - target[0]) + abs(x[1] - target[1]);
        };
        for(auto x: ghosts) {
            distances.push_back(distance(x));
        }
        return *min_element(distances.begin(), distances.end()) > distance(vector<int>(2, 0));
    }
};