class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<4901> s(1);
        for(auto &r: mat) {
            bitset<4901> t;
            for(auto &c: r) {
                t = t | (s << c);
            }
            swap(s, t);
        }
        int ans = INT_MAX;
        for(int i = 0; i <= 4901; i++) {
            if(s[i]) {
                ans = min(ans, abs(target - i));
            }
        }
        return ans;
    }
};