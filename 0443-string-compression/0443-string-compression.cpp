class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int l = 0, cnt = 1;
        for(int i = 1; i < n; i++) {
            if(chars[i - 1] == chars[i]) {
                cnt++;
            }
            else {
                chars[l++] = chars[i - 1];
                if(cnt > 1) {
                    string st = to_string(cnt);
                    for(char c: st) {
                        chars[l++] = c;
                    }
                }
                cnt = 1;
            }
        }
        chars[l++] = chars[n - 1];
        if(cnt > 1) {
            string st = to_string(cnt);
            for(char c: st) {
                chars[l++] = c;
            }
        }
        return l;
    }
};