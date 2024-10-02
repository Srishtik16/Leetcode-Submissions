class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        string l = "", r = "";
        int ans = 0;
        for(int i = 0; i < n; i++) {
            l += text[i];
            r = text[n - i - 1] + r;
            if(l == r) {
                ans++;
                l = "", r = "";
            }
        }
        return ans;
    }
};