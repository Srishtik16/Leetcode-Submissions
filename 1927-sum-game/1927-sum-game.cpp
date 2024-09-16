class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int f = 0, s = 0;
        vector<int> fh, sh;
        for(int i = 0; i < n; i++) {
            if(i < n / 2) {
                f += (num[i] == '?' ? 0 : num[i] - '0');
                if(num[i] == '?') {
                    fh.push_back(i);
                }
            }
            else {
                s += (num[i] == '?' ? 0 : num[i] - '0');
                if(num[i] == '?') {
                    sh.push_back(i);
                }
            }
        }
        if(f > s) {
            if(fh.size() > sh.size()) {
                return true;
            }
            else {
                int l = sh.size() - fh.size();
                return 2 * (f - s) != 9 * l;
            }
        }
        else {
            if(fh.size() < sh.size()) {
                return true;
            }
            else {
                int l = fh.size() - sh.size();
                return 2 * (s - f) != 9 * l;
            }
        }
        return false;
    }
};