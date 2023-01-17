class Solution {
public:
    int maxVowels(string s, int k) {
        for(char &c: s) {
            if(c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = 'a';
            }
        }
        int cnt = 0;
        for(int i = 0; i < k; i++) {
            cnt += s[i] == 'a';
        }
        int ans = cnt, n = s.size(); 
        for(int i = k; i < n; i++) {
            cnt -= s[i - k] == 'a';
            cnt += s[i] == 'a';
            ans = max(ans, cnt);
        }
        return ans;
    }
};