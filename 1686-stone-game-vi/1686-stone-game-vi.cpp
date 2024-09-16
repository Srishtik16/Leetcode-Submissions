class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<int> order(aliceValues.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int &x, const int &y) {
            return aliceValues[x] + bobValues[x] > aliceValues[y] + bobValues[y]; 
        });
        bool turn = true;
        int alice = 0, bob = 0;
        for(auto x: order) {
            if(turn) {
                alice += aliceValues[x];
            }
            else {
                bob += bobValues[x];
            }
            turn ^= 1;
        }
        return alice == bob ? 0 : abs(alice - bob) / (alice - bob);
    }
};