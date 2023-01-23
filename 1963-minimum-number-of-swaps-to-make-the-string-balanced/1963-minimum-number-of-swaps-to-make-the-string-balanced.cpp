class Solution {
public:
    int minSwaps(string s) {
        int balance = 0, mismatch = 0;
        for(char c: s) {
            balance += (c == '[' ? 1 : -1);
            if(balance == -1) {
                mismatch++;
                balance = 0;
            }
        }
        return  (mismatch + 1) / 2;
    }
};