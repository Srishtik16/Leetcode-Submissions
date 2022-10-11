class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> m1, m2;
        for(auto x: words1) {
            m1[x]++;
        }
        for(auto x: words2) {
            m2[x]++;
        }
        int ans = 0;
        for(auto x: words1) {
            ans += m1[x] == 1 && m2[x] == 1;
        }
        return ans;
    }
};