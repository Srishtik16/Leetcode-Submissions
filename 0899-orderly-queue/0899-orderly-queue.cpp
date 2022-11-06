class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            string ans = s;
            int iter = 1000;
            while(iter--) {
                rotate(s.begin(), s.begin() + 1, s.end());
                ans = ans > s ? s : ans;
            }
            return ans;
        }
        else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};