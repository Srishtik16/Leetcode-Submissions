class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int, greater<int>> ms(stones.begin(), stones.end());
        while(ms.size() > 1) {
            int last = *ms.begin();
            ms.erase(ms.begin());
            int slast = *ms.begin();
            ms.erase(ms.begin());
            if(last == slast) {
                if(ms.size() == 0) {
                    return 0;
                }
            }
            else {
                ms.insert(abs(last - slast));
            }
        }
        return *ms.begin();
    }
};