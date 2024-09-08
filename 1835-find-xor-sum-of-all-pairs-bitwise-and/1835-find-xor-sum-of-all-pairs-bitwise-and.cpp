class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        map<int, int> m1, m2;
        for(auto x: arr1) {
            for(int i = 0; i < 31; i++) {
                if((1LL << i) & x) {
                    m1[i]++;
                }
            }
        }
        for(auto x: arr2) {
            for(int i = 0; i < 31; i++) {
                if((1LL << i) & x) {
                    m2[i]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 31; i++) {
            if((m1[i] * 1LL * m2[i]) & 1) {
                ans += (1LL << i);
            }
        }
        return ans;
    }
};