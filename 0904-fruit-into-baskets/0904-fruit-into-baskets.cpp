class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        int n = fruits.size();
        map<int, int> m;
        int ans = 0;
        while(l <= r && r < n) {
            m[fruits[r]]++;
            if(m.size() <= 2) {
                int val = 0;
                for(auto x: m) {
                    val += x.second;
                }
                ans = max(ans, val);
            }
            while(m.size() > 2) {
                m[fruits[l]]--;
                if(m[fruits[l]] == 0) {
                    m.erase(fruits[l]);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};