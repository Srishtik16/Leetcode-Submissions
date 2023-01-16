class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        multiset<vector<int>> ms(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        while(ms.size() > 1) {
            auto it = ms.begin();
            auto f = *it;
            advance(it, 1);
            auto s = *it;
            if(s[0] <= f[1]) {
                ms.erase(ms.find(f));
                ms.erase(ms.find(s));
                vector<int> val = {f[0], max(s[1], f[1])};
                ms.insert(val);
            }
            else {
                ans.push_back(f);
                ms.erase(ms.find(f));
            }
        }
        ans.push_back(*ms.begin());
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};