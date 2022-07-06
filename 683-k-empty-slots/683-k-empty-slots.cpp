class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        set<int> indices;
        for(int days = 0; days < n; days++) {
            if(indices.empty()) {
                indices.insert(bulbs[days]);
                continue;
            }
            indices.insert(bulbs[days]);
            auto it1 = indices.lower_bound(bulbs[days]);
            auto it2 = indices.upper_bound(bulbs[days]);
            int diffLeft = -1, diffRight = -1;
            if(it1 != indices.begin()) {
                advance(it1, -1);
                diffLeft = abs(bulbs[days] - *it1 - 1);
            }
            if(it2 != indices.end()) {
                diffRight = abs(*it2 - bulbs[days] - 1);
            }
            cout << *it1 << " " << *it2 << endl;
            cout << diffLeft << " " << diffRight << endl;
            if(diffLeft == k || diffRight == k) {
                return days + 1;
            }
        }
        return -1;
    }
};