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
    void findSecretWord(vector<string>& wordlist, Master& master) {
        auto match = [&](string x, string y) {
            int cnt = 0;
            for(int i = 0; i < 6; i++) {
                cnt += x[i] == y[i];
            }
            return cnt;
        };
        for(int i = 0; i < 10; i++) {
            random_shuffle(wordlist.begin(), wordlist.end());
            int ind = random(0, wordlist.size() - 1, int);
            int matches = master.guess(wordlist[ind]);
            if(matches == 6) {
                break;
            }
            string s = wordlist[ind];
            vector<string> ms1;
            for(auto x: wordlist) {
                if(match(x, s) == matches && x != s) {
                    ms1.push_back(x);
                }
            }
            wordlist = ms1;
        }
    }
};