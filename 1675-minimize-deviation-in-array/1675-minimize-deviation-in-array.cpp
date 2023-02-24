class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        for(auto &x: nums) {
            if(x % 2 != 0) {
                x *= 2;
            }
        }
        multiset<int> ms(nums.begin(), nums.end());
        int dev = INT_MAX;
        while(*ms.rbegin() % 2 == 0) {
            dev = min(dev, abs(*ms.begin() - *ms.rbegin()));
            int x = *ms.rbegin();
            x /= 2;
            ms.erase(ms.find(*ms.rbegin()));
            ms.insert(x);
        }
        dev = min(dev, abs(*ms.begin() - *ms.rbegin()));
        return dev;
    }
};