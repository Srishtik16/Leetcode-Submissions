class Solution {
public:
    int shortestWay(string source, string target) {
        map<char, vector<int>> indices;
        int n = source.size();
        for(int i = 0; i < n; i++) {
            indices[source[i]].push_back(i);
        }
        for(char c: target) {
            if(indices.find(c) == indices.end()) {
                return -1;
            }
        }
        int curr = -1, ans = 1;
        for(int i = 0; i < (int)target.size(); i++) {
            char c = target[i];
            auto it = upper_bound(indices[c].begin(), indices[c].end(), curr);
            if(it == indices[c].end()) {
                ans++;
                i--;
                curr = -1;
            }
            else {
                curr = *it;
            }
        }
        return ans;
    }
};