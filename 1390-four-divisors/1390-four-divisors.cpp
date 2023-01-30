class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums) {
            int cntDiv = 0, sumDiv = 0;
            for(int i = 1; i * i <= x; i++) {
                if(x % i == 0) {
                    if(x / i == i) {
                        sumDiv += i;
                        cntDiv += 1;
                    }
                    else {
                        sumDiv += i;
                        sumDiv += x / i;
                        cntDiv += 2;
                    }
                }
            }
            if(cntDiv == 4) {
                sum += sumDiv;
            }
        }
        return sum;
    }
};