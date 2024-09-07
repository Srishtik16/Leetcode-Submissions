class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int ans = 0, n = word.size();
        for(int i = 0; i < n - 1; i++) {
            if(abs(word[i] - word[i + 1]) <= 1) {
                ans++;
                word[i + 1] = '$';
            }
        }
        return ans;
    }
};