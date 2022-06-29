class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.rbegin(), citations.rend());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += citations[i] >= i + 1;
        }
        return ans;
    }
};