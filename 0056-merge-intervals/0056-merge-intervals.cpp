class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        multiset<vector<int>> ms(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        auto isOverlap = [&](auto range1, auto range2) {
            return min(range1[1], range2[1]) >= max(range1[0], range2[0]);
        };
        while(ms.size() > 1) {
            auto first = *ms.begin();
            ms.erase(ms.begin());
            auto second = *ms.begin();
            ms.erase(ms.begin());
            if(isOverlap(first, second)) {
                vector<int> overlapped = {min(first[0], second[0]), max(first[1], second[1])};
                ms.insert(overlapped);
            }
            else {
                ans.push_back(first);
                ms.insert(second);
            }
        }
        ans.push_back(*ms.begin());
        return ans;
    }
};