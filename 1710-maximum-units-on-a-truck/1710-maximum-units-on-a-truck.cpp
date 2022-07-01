class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [&](const auto &x, const auto &y) {
            if(x[1] == y[1]) {
                return x[0] > y[0];
            }
            return x[1] > y[1];
        });
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int canTake = min(truckSize, boxTypes[i][0]);
            ans += canTake * boxTypes[i][1];
            truckSize -= canTake;
        }
        return ans;
    }
};