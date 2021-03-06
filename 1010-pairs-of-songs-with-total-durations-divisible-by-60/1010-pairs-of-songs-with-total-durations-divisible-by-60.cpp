class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int, int> m;
        int ans = 0;
        for(auto &x: time) {
            x %= 60;
            if(m.find((60 - x + 60) % 60) != m.end()) {
                ans += m[(60 - x + 60) % 60];
            }
            m[x]++;
        }
        return ans;
    }
};