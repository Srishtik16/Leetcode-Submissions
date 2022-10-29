class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> m;
        for(auto x: arr) {
            m[x]++;
        }
        for(auto x: arr) {
            if(x == 0) {
                if(m[x] > 1) {
                    return true;
                }
            }
            else if(m.find(2 * x) != m.end()) {
                return true;
            }
        }
        return false;
    }
};