class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        int sumn = (m + n) * mean - sum;
        sumn -= n;
        if(sumn < 0) {
            return vector<int>();
        }
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++) {
            int mx = min(sumn, 5);
            ans[i] += mx;
            sumn -= mx;
        }
        if(sumn > 0) {
            return vector<int>();
        }
        return ans;
    }
};