class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        long long dig = (intLength + 1) / 2;
        for(auto x: queries) {
            long long base = 1;
            for(int i = 1; i < dig; i++) {
                base *= 10;
            }
            int num = base + x - 1;
            if(to_string(num).length() > dig) {
                ans.push_back(-1);
            }
            else {
                string res = to_string(num);
                if(intLength % 2 == 0) {
                    string resc = res;
                    reverse(resc.begin(), resc.end());
                    res += resc;
                }
                else {
                    string resc = res;
                    resc.pop_back();
                    reverse(resc.begin(), resc.end());
                    res += resc;
                }
                ans.push_back(stoll(res));
            }
        }
        return ans;
    }
};