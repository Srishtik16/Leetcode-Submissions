class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        multiset<int> ms(nums.begin(), nums.end());
        while(k--) {
            int x = *ms.begin();
            ms.erase(ms.begin());
            x++;
            ms.insert(x);
        }
        long long product = 1;
        for(auto x: ms) {
            product *= x;
            product %= (int)(1e9 + 7);
        }
        return product % (int)(1e9 + 7);
    }
};