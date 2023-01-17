class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) {
            return 0;
        }
        else if(k % 2 == 0) {
            return kthGrammar(n - 1, k / 2) ^ 1;
        }
        else {
            return kthGrammar(n - 1, k / 2 + 1);
        }
    }
};