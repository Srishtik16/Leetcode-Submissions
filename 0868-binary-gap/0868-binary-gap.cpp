class Solution {
public:
    int binaryGap(int n) {
        string s = "";
        while(n > 0) {
            s += (n % 2 ? '1' : '0');
            n /= 2;
        }
        vector<int> indexes;
        for(int i = 0; i < size(s); i++) {
            if(s[i] == '1') {
                indexes.push_back(i);
            }
        }
        int ans = 0;
        for(int i = 1; i < size(indexes); i++) {
            ans = max(ans, indexes[i] - indexes[i - 1]);
        }
        return ans;
    }
};