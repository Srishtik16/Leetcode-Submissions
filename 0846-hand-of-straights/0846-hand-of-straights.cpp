class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> ms(hand.begin(), hand.end());
        while(!ms.empty()) {
            int x = *ms.begin();
            int kc = groupSize;
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