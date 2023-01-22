class Solution {
public:
    bool isReachable(int tx, int ty) {
        int sx = 1, sy = 1;
        while(tx % 2 == 0) {
            tx /= 2;
        }
        while(ty % 2 == 0) {
            ty /= 2;
        }
        while(tx >= sx && ty >= sy) {
            if(tx > ty) {
                if(sy == ty) {
                    return (tx - sx) % ty == 0;
                }
                tx %= ty;
            }
            else {
                if(sx == tx) {
                    return (ty - sy) % tx == 0;
                }
                ty %= tx;
            }
        }
        return false;
    }
};