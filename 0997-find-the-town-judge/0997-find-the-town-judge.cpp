class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDeg(n + 1, 0), outDeg(n + 1, 0);
        for(auto x: trust) {
            outDeg[x[0]]++;
            inDeg[x[1]]++;
        }
        vector<int> candidate;
        for(int i = 1; i <= n; i++) {
            if(inDeg[i] == n - 1 && outDeg[i] == 0) {
                candidate.push_back(i);
            }
        }
        if(candidate.size() > 1 || candidate.empty()) {
            return -1;
        }
        else {
            return candidate.back();
        }
    }
};