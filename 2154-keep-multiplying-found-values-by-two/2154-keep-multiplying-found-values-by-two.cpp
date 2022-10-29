class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while(true) {
            if(count(nums.begin(), nums.end(), original) > 0) {
                original *= 2;
            }
            else {
                break;
            }
        }
        return original;
    }
};