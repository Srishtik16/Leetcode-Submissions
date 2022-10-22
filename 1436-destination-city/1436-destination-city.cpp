class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> out;
        for(auto x: paths) {
            out[x[0]]++;
        }
        for(auto x: paths) {
            if(out[x[1]] == 0) {
                return x[1];
            }
        }
        return "";
    }
};