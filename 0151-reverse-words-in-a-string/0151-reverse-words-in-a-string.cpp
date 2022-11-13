class Solution {
public:
    string reverseWords(string s) {
        string cat = "";
        vector<string> a;
        for(char c: s) {
            if(c == ' ') {
                if(cat != "") {
                    a.push_back(cat);
                }
                cat = "";
            }
            else {
                cat += c;
            }
        }
        if(cat != "") {
            a.push_back(cat);
        }
        cat = "";
        reverse(a.begin(), a.end());
        for(auto x: a) {
            while(x.back() == ' ') {
                x.pop_back();
            }
            reverse(x.begin(), x.end());
            while(x.back() == ' ') {
                x.pop_back();
            }
            reverse(x.begin(), x.end());
            cat += x;
            cat += " ";
        }
        cat.pop_back();
        return cat;
    }
};