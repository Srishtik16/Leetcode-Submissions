class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(30, 0);
        for(auto x: candidates) {
            for(int i = 30; i >= 0; i--) {
                if((1LL << i) & x) {
                    bits[i]++;
                }
            }
        }
        return *max_element(bits.begin(), bits.end());
    }
};