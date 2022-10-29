class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {plantTime[i], growTime[i]};
        }
        sort(a.begin(), a.end(), [&](const auto &x, const auto &y){
            if(x.second == y.second) {
                return x.first < y.first;
            }
            return x.second > y.second;
        });
        int currTime = 0, maxTime = 0;
        for(auto x: a) {
            currTime += x.first;
            maxTime = max(maxTime, currTime + x.second);
        }
        return maxTime;
    }
};