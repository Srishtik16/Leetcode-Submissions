class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int ans = 0;
        map<pair<int, int>, int> count;
        for(auto &coordinate: coordinates) {
            int x = coordinate[0];
            int y = coordinate[1];
            for(int i = 0; i <= k; i++) {
                int nx = x ^ i;
                int ny = y ^ (k - i);
                if(count.find({nx, ny}) != count.end()) {
                    ans += count[{nx, ny}];
                }
            }
            count[{x, y}]++;
        }
        return ans;
    }
};