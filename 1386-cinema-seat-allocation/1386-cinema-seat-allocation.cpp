class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        set<vector<int>> reserved;
        set<int> rows;
        for(auto &x: reservedSeats) {
            reserved.insert(x);
            rows.insert(x[0]);
        }
        auto found = [&] (vector<int> a) {
            return reserved.find(a) == reserved.end();
        };
        int ans = 0;
        for(auto i: rows) {
            if(found({i, 2}) && found({i, 3}) && found({i, 4}) && found({i, 5}) && found({i, 6}) && found({i, 7}) && found({i, 8}) && found({i, 9})){
                ans += 2;
            }
            else if(found({i, 2}) && found({i, 3}) && found({i, 4}) && found({i, 5})) {
                ans++;
            }
            else if(found({i, 4}) && found({i, 5}) && found({i, 6}) && found({i, 7})) {
                ans++;
            }
            else if(found({i, 6}) && found({i, 7}) && found({i, 8}) && found({i, 9})) {
                ans++;
            }
        }
        ans += (n - rows.size()) * 2;
        return ans;
    }
};