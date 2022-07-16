class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n = list1.size();
        int m = list2.size();
        map<string, int> m1, m2;
        for(int i = 0; i < n; i++) {
            m1[list1[i]] = i;
        }
        for(int i = 0; i < m; i++) {
            m2[list2[i]] = i;
        }
        vector<string> res;
        int ans = INT_MAX;
        for(auto x: m1) {
            if(m2.find(x.first) != m2.end()) {
                if(x.second + m2[x.first] + 2 < ans) {
                    ans = x.second + m2[x.first] + 2;
                }
            }
        }
        for(auto x: m1) {
            if(m2.find(x.first) != m2.end()) {
                if(x.second + m2[x.first] + 2 == ans) {
                    res.push_back(x.first);
                }
            }
        }
        return res;
    }
};