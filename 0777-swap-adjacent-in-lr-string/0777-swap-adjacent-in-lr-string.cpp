class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;
        while(i < n || j < n) {
            while(start[i] == 'X') {
                i++;
            }
            while(end[j] == 'X') {
                j++;
            }
            if(start[i] != end[j]) {
                return false;
            }
            if(start[i] == 'R' && i > j) {
                return false;
            }
            if(start[i] == 'L' && i < j) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};