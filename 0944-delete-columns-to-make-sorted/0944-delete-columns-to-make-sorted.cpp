class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int del = 0;
        int n = strs.size(), m = strs[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j > 0 && strs[j][i] < strs[j - 1][i]) {
                    del++;
                    break;
                }
            }
        }
        return del;
    }
};