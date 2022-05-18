class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({a[i], i});
        }
        sort(vec.begin(), vec.end());
        int l = 0, r = n - 1;
        while(l < r) {
            if(vec[l].first + vec[r].first == target) {
                return {vec[l].second, vec[r].second};
            }
            else if(vec[l].first + vec[r].first < target) {
                l++;
            }
            else {
                r--;
            }
        }
        return {0, 0};
    }
};