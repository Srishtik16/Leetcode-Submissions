class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int mx1 = 1e8, mx2 = 1e8, sum = 0;
        for(auto x: nums) {
            if(x % 3 == 1) {
                mx2 = min(mx2, mx1 + x);
                mx1 = min(mx1, x);
            }
            else if(x % 3 == 2) {
                mx1 = min(mx1, mx2 + x);
                mx2 = min(mx2, x);
            }
            sum += x;
        }
        if(sum % 3 == 0) {
            return sum;
        }
        else if(sum % 3 == 1) {
            return sum - mx1;
        }
        else {
            return sum - mx2;
        }
    }
};