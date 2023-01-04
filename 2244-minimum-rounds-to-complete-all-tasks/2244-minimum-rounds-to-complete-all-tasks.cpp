class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> m;
        for(auto x: tasks) {
            m[x]++;
        }
        int ans = 0;
        for(auto x: m) {
            if(x.second == 1) {
                return -1;
            }
            ans += (x.second + 2) / 3;
        }
        return ans;
    }
};