class Solution {
public:
    string recurse(int &i, string s) {
        if(i == s.size()) {
            return "";
        }
        int mul = 0;
        string ans = "";
        while(i < s.size()) {
            if(s[i] >= '0' && s[i] <= '9') {
                mul *= 10;
                mul += (s[i] - '0');
            }
            else if(s[i] == '[') {
                string temp = recurse(++i, s);
                while(mul > 0) {
                    ans += temp;
                    mul--;
                }
            }
            else if(s[i] == ']') {
                return ans;
            }
            else {
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
    string decodeString(string s) {
        int i = 0;
        return recurse(i, s);
    }
};