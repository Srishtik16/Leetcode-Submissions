class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, vector<string>> m;
        auto wordCount = [&](string s) {
            s += " ";
            vector<string> w;
            string word = "";
            for(char c: s) {
                if(c == ' ') {
                    if(!word.empty()) {
                        w.push_back(word);
                    }
                    word = "";
                }
                else {
                    word += c;
                }
            }
            return (int)w.size();
        };
        int n = messages.size();
        for(int i = 0; i < n; i++) {
            m[senders[i]].push_back(messages[i]);
        }
        map<string, int> count;
        for(auto x: m) {
            for(auto y: x.second) {
                count[x.first] += wordCount(y);
            }
        }
        vector<pair<int, string>> vec;
        for(auto x: count) {
            // cout << x.first << " " << x.second << endl;
            vec.push_back({x.second, x.first});
        }
        sort(vec.begin(), vec.end(), [&](const auto &x, const auto &y) {
            if(x.first == y.first) {
                return x.second > y.second;
            }
            return x.first > y.first;
        });
        return vec[0].second;
    }
};