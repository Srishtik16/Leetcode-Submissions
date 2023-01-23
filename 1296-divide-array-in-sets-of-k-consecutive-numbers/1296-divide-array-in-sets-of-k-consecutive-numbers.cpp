class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> ms(nums.begin(), nums.end());
        while(!ms.empty()) {
            int x = *ms.begin();
            int kc = k;
            while(kc--) {
                if(ms.find(x) != ms.end()) {
                    ms.erase(ms.find(x));
                    x++;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};