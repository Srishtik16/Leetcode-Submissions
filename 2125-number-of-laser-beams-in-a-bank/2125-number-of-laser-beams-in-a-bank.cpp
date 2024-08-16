class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<string> updatedBank;
        for(auto x: bank) {
            if(count(x.begin(), x.end(), '0') == x.size()) {
                continue;
            }
            updatedBank.push_back(x);
        }
        int n = updatedBank.size();
        int ans = 0;
        for(int i = 1; i < n; i++) {
            ans += count(updatedBank[i].begin(), updatedBank[i].end(), '1') * count(updatedBank[i - 1].begin(), updatedBank[i - 1].end(), '1');
        }
        return ans;
    }
};