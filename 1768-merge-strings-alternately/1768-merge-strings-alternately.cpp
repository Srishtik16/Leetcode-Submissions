class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string ans = "";
        int i = 0, j = 0;
        bool ok = true;
        while(i < n && j < m) {
            if(ok) {
                ans += word1[i];
                i++;
            }
            else {
                ans += word2[j];
                j++;
            }
            ok ^= 1;
        }
        while(i < n) {
            ans += word1[i];
            i++;
        }
        while(j < m) {
            ans += word2[j];
            j++;
        }
        return ans;
    }
};