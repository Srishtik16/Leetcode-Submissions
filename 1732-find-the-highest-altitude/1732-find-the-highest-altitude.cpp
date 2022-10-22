class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, curr = 0;
        for(auto x: gain) {
            curr += x;
            ans = max(ans, curr);
        }
        return ans;
    }
};