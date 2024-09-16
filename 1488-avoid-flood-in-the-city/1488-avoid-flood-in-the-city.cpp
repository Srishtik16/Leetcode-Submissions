class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        // iterate from left to right
        // if we find a 0, our capacity is ++
        // if we find a repeat element > 0 with no capacity -> flood
        // else we add it to the vector and update the capacity
        set<int> dry;
        map<int, int> full;
        int n = rains.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {
                dry.insert(i);
                ans[i] = 1;
            }
            else {
                if(full.find(rains[i]) != full.end()) {
                    if(dry.lower_bound(full[rains[i]]) != dry.end()) {
                        ans[*dry.lower_bound(full[rains[i]])] = rains[i];
                        dry.erase(*dry.lower_bound(full[rains[i]]));
                    }
                    else {
                        return vector<int>{};
                    }
                }
                full[rains[i]] = i;
                ans[i] = -1;
            }
        }
        return ans;
    }
};