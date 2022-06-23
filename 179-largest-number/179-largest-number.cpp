class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;
        for(auto x: nums) {
            a.push_back(to_string(x));
        }
        sort(a.begin(), a.end(), [&](const auto &x, const auto &y) {
            string f = x + y;
            string s = y + x;
            return f > s;
        });
        if(a[0] == "0") {
            return a[0];
        } 
        string ans = "";
        for(auto x: a) {
            ans += x;
        }
        return ans;
    }
};