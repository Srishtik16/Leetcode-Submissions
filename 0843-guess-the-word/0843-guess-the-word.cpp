/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        auto count = [&](string s, string t) {
            int cnt = 0;
            for(int i = 0; i < 6; i++) {
                cnt += s[i] == t[i];
            }
            return cnt;
        };
        while(true) {
            int r = random(0, (int)words.size() - 1, int);
            int g = master.guess(words[r]);
            if(g == 6) {
                break;
            }
            vector<string> tempwords;
            for(auto &x: words) {
                if(count(x, words[r]) == g && x != words[r]) {
                    tempwords.push_back(x);
                }
            }
            swap(tempwords, words);
        }
    }
};