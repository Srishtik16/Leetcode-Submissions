class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bitmasks(n);
        for(int i = 0; i < n; i++) {
            for(char c: words[i]) {
                bitmasks[i] |= (1LL << (c - 'a'));
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if((bitmasks[i] & bitmasks[j]) == 0) {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return ans;
    }
};