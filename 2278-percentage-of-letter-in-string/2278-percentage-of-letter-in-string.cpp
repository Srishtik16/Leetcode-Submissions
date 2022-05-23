class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for(char c: s) {
            cnt += c == letter;
        }
        int n = s.size();
        // cout << cnt << endl;
        return floor((cnt * 1.0 / n) * 100);
    }
};