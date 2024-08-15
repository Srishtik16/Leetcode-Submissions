class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> bad;
        int sum = 0;
        vector<int> ans;
        for(int i = 1;; i++) {
            if(bad.find(k - i) == bad.end()) {
                ans.push_back(i);
                sum += i;
                bad.insert(i);
            }
            if(ans.size() == n) {
                return sum;
            }
        }
        
        return -1;
    }
};