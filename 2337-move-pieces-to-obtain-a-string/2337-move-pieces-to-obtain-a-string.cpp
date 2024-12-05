class Solution {
public:
    bool canChange(string start, string end) {
        string s = "", t = "";
        vector<vector<int>> v(4);
        for(char c: start) {
            if(c != '_') {
                s += c;
            }
        }
        for(char c: end) {
            if(c != '_') {
                t += c;
            }
        }
        if(s != t) {
            return false;
        }
        for(int i = 0; i < (int)start.size(); i++) {
            if(start[i] == '_') {
                continue;
            }
            if(start[i] == 'L') {
                v[0].push_back(i);
            }
            else {
                v[1].push_back(i);
            }
        } 
        for(int i = 0; i < (int)end.size(); i++) {
            if(end[i] == '_') {
                continue;
            }
            if(end[i] == 'L') {
                v[2].push_back(i);
            }
            else {
                v[3].push_back(i);
            }
        } 
        for(int i = 0; i < v[0].size(); i++) {
            if(v[0][i] < v[2][i]) {
                return false;
            }
        }
        for(int i = 0; i < v[1].size(); i++) {
            if(v[1][i] > v[3][i]) {
                return false;
            }
        }
        return true;
    }
};