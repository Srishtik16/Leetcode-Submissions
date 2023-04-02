class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());
        for(int i = 0; i < n; i++) {
            long long need = (success + spells[i] - 1) / spells[i];
            int ind = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            // cout << need << " " << ind << endl;
            ans[i] = m - ind;
        }
        return ans;
    }
};