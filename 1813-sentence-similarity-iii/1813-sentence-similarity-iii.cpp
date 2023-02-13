class Solution {
public:
    bool areSentencesSimilar(string s, string t) {
        auto getWords = [&](string s) {
            vector<string> words;
            s += " ";
            string word = "";
            for(char c: s) {
                if(c == ' ') {
                    words.push_back(word);
                    word = "";
                }
                else {
                    word += c;
                }
            }
            return words;
        };
        vector<string> sw = getWords(s);
        vector<string> tw = getWords(t);
        if((int)sw.size() < (int)tw.size()) {
            swap(sw, tw);
        }
        int i = 0, j = 0;
        while(j < (int)tw.size()) {
            if(sw[i] != tw[j]) {
                break;
            }
            i++;
            j++;
        }
        while(!tw.empty() && sw.back() == tw.back()) {
            sw.pop_back();
            tw.pop_back();
        }
        int l = i, r = (int)sw.size() - 1;
        cout << l << " " << r << endl;
        if(l > r) {
            return true;
        }
        else {
            int wordsNotFromt = r - l + 1;
            if((int)sw.size() - (int)tw.size() >= wordsNotFromt || l == tw.size() || (int)sw.size() - 1 - (int)tw.size() == r) {
                return true;
            }
            else {
                return false;
            }
        }
    }
};