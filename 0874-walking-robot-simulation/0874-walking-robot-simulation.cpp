class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // map obstacles as x -> yi and y -> xi
        // if in direction and pos, obstacle is found, go to obs - 1 coord else + k
        // simulate
        map<int, set<int>> mx, my;
        for(auto x: obstacles) {
            mx[x[0]].insert(x[1]);
            my[x[1]].insert(x[0]);
        }
        int x = 0, y = 0, ans = 0;
        bool dir = true, axes = false; // dir +/- (T/F), axes X/Y (T/F)
        for(auto &c: commands) {
            if(c == -1) {
                if(axes) {
                    dir ^= 1;
                }
                axes ^= 1;
            }
            else if(c == -2) {
                if(!axes) {
                    dir ^= 1;
                }
                axes ^= 1;
            }
            else {
                int nx = x, ny = y;
                int which = 0;
                for(int i = 1; i <= c; i++) {
                    if(axes) {
                        int add = dir ? 1 : -1;
                        if(my[ny].find(nx + add * i) != my[ny].end()) {
                            nx = nx + add * (i - 1);
                            which = 1;
                            break;
                        }
                    }
                    else {
                        int add = dir ? 1 : -1;
                        if(mx[nx].find(ny + add * i) != mx[nx].end()) {
                            ny = ny + add * (i - 1);
                            which = 1;
                            break;
                        }
                    }
                }
                if(!which) {
                    axes ? nx = nx + (dir ? 1 : -1) * c : ny = ny + (dir ? 1 : -1) * c; 
                }
                x = nx, y = ny;
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};