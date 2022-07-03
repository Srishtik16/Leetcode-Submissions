class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        multiset<int> ms(changed.begin(), changed.end());
        vector<int> ans;
        if(ms.count(0) & 1) {
            return ans;
        }
        ans.assign(ms.count(0) / 2, 0);
        ms.erase(0);
        while(!ms.empty()) {
            int x = *ms.begin();
            if(x == 0) {
                if(ms.count(x) >= 2) {
                    ans.push_back(0);
                    ms.erase(ms.find(0));
                    ms.erase(ms.find(0));
                }
                else {
                    return vector<int>();
                }
            }
            else if(ms.find(x * 2) != ms.end()) {
                ans.push_back(x);
                ms.erase(ms.find(x));
                ms.erase(ms.find(x * 2));
            }
            else if(x % 2 == 0 && ms.find(x / 2) != ms.end()) {
                ans.push_back(x / 2);
                ms.erase(ms.find(x / 2));
                ms.erase(ms.find(x));
            }
            else {
                return vector<int>();
            }
        }
        return ans;
    }
};