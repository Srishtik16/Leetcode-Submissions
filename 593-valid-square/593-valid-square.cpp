class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        auto distance = [&](vector<int> &p1, vector<int> &p2) {
            return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        };
        map<vector<int>, int> m;
        m[p1]++;
        m[p2]++;
        m[p3]++;
        m[p4]++;
        if(m.size() < 4) {
            return false;
        }
        int d2 = distance(p1, p2);
        int d3 = distance(p1, p3);
        int d4 = distance(p1, p4);
        if(d2 == 0 || d3 == 0 || d4 == 0) {
            return false;
        }
        if(d2 == d3 && 2 * d2 == d4) {
            if(distance(p4, p2) == distance(p4, p3)) {
                return true;
            }
        }
        if(d2 == d4 && 2 * d2 == d3) {
            if(distance(p3, p2) == distance(p3, p4)) {
                return true;
            }
        }
        if(d3 == d4 && 2 * d3 == d2) {
            if(distance(p2, p3) == distance(p2, p4)) {
                return true;
            }
        }
        return false;
    }
};