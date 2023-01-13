class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> odda, evena, oddb, evenb;
        for(auto x: nums) {
            if(x & 1) {
                odda.push_back(x);
            }
            else {
                evena.push_back(x);
            }
        }
        for(auto x: target) {
            if(x & 1) {
                oddb.push_back(x);
            }
            else {
                evenb.push_back(x);
            }
        }
        sort(odda.begin(), odda.end());
        sort(evena.begin(), evena.end());
        sort(oddb.begin(), oddb.end());
        sort(evenb.begin(), evenb.end());
        long long res = 0;
        for(int i = 0; i < size(odda); i++) {
            res += abs(odda[i] - oddb[i]) / 2;
        }
        for(int i = 0; i < size(evena); i++) {
            res += abs(evena[i] - evenb[i]) / 2;
        }
        return res / 2;
    }
};