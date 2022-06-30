class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n % 2 == 0) {
            int med1 = nums[n / 2 - 1];
            int med2 = nums[n / 2];
            int cost1 = 0, cost2 = 0;
            for(auto x: nums) {
                cost1 += abs(x - med1);
                cost2 += abs(x - med2);
            }
            return min(cost1, cost2);
        }
        else {
            int med = nums[n / 2];
            int cost = 0;
            for(auto x: nums) {
                cost += abs(x - med);
            }
            return cost;
        }
    }
};