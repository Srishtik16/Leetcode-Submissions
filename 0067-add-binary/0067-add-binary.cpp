class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.size() < b.size()) {
            swap(a, b);
        }
        while(b.size() < a.size()) {
            b += '0';
        }
        int n = a.size();
        string ans = "";
        int sum = 0, carry = 0;
        for(int i = 0; i < n; i++) {
            sum = (a[i] - '0' + b[i] - '0' + carry);
            carry = sum / 2;
            sum %= 2;
            ans += to_string(sum);
        }
        if(carry != 0) {
            ans += to_string(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};