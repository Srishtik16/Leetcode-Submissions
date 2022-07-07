class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end(), [&](const auto &x, const auto &y) {
            if(x[0] == y[0]) {
                return x[1] > y[1];
            }
            return x[0] < y[0];
        });
        stack<vector<int>> s;
        int ans = 0;
        for(auto x: properties) {
            while(!s.empty() && s.top()[0] < x[0] && s.top()[1] < x[1]) {
                s.pop();
                ans++;
            } 
            s.push(x);
        }
        return ans;
    }
};