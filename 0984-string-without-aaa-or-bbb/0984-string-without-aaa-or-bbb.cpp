class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        bool swapped = false;
        if(a < b) {
            swap(a, b);
            swapped = true;
        }
        int diff = abs(a - b);
        while(diff > 1 && a > 0 && b > 0) {
            a -= 2;
            b--;
            ans += "aab";
            diff = abs(a - b);
        }
        while(a > 0 && b > 0) {
            ans += "ab";
            a--;
            b--;
        }
        if(a > 0) {
            ans += string(a, 'a');
        }
        if(swapped) {
            for(char &c: ans) {
                if(c == 'a') {
                    c = 'b';
                }
                else {
                    c = 'a';
                }
            } 
        }
        return ans;
    }
};
