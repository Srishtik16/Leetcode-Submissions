class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        map<char, vector<int>> index;
        for(int i = 0; i < n; i++) {
            index[s[i]].push_back(i);
        }
        long long ans = 0;
        for(char c = 'a'; c <= 'z'; c++) {
            index[c].insert(index[c].begin(), -1);
            index[c].push_back(n);
            for(int i = 1; i < (int)index[c].size() - 1; i++) {
                int l = index[c][i] - index[c][i - 1];
                int r = n - index[c][i];
                ans += l * 1LL * r;
            }
        }
        return ans;
    }
};