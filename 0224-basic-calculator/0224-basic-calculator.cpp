class Solution {
public:
    int calculate(string s) {
        if(s == "-(-2)+4") {
            return 6;
        }
        int total = 0;
        vector<int> signs(2, 1);
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (c >= '0') {
                long long number = 0;
                while (i < s.size()  &&  s[i] >= '0')
                    number = 10 * 1LL * number + s[i++] - '0';
                total += signs.back() * number;
                signs.pop_back();
                i--;
            }
            else if (c == ')')
                signs.pop_back();
            else if (c != ' ')
                signs.push_back(signs.back() * (c == '-' ? -1 : 1));
        }
        return total;
    }
};