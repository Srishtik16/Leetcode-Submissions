class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        map<char, int> ml;
        for(char c: letters) {
            ml[c]++;
        }
        int ans = 0;
        for(int mask = 0; mask < (1LL << n); mask++) {
            string s = "";
            for(int i = 0; i < n; i++) {
                if((1LL << i) & mask) {
                    s += words[i];
                }
            }
            map<char, int> ms;
            for(char c: s) {
                ms[c]++;
            }
            bool ok = true;
            for(char c = 'a'; c <= 'z'; c++) {
                if(ml[c] < ms[c]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                int scores = 0;
                for(char c: s) {
                    scores += score[c - 'a'];
                }
                ans = max(ans, scores);
            }
        }
        return ans;
    }
};