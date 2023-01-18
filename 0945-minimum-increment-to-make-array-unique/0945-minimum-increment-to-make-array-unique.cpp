const int MaxN = 1e6 + 5;
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        multiset<int> ms(nums.begin(), nums.end());
        set<int> uniques(nums.begin(), nums.end());
        for(auto x: uniques) {
            ms.erase(ms.find(x));
        }
        vector<bool> vis(MaxN, false);
        for(auto x: nums) {
            vis[x] = true;
        }
        int moves = 0;
        for(int i = 1; i < MaxN; i++) {
            if(ms.empty()) {
                break;
            }
            if(!vis[i]) {
                if(*ms.begin() > i) {
                    continue;
                }
                moves += abs(i - *ms.begin());
                ms.erase(ms.begin());
            }
        }
        return moves;
    }
};