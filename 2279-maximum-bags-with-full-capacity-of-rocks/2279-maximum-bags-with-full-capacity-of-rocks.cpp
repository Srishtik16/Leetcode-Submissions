class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<pair<int, int>> vec;
        for(int i = 0; i < capacity.size(); i++) {
            vec.push_back({capacity[i], rocks[i]});
        }
        sort(vec.begin(), vec.end(), [&](const auto &x, const auto &y) {
           return x.first - x.second < y.first - y.second; 
        });
        int cnt = 0;
        for(auto &x: vec) {
            int add = min(additionalRocks, x.first - x.second);
            additionalRocks -= add;
            x.second += add;
        }
        for(auto x: vec) {
            cnt += x.first - x.second == 0;
        }
        return cnt;
    }
};