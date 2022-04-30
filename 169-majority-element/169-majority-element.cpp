class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0], cnt = 0;
        for(auto x: nums) {
            if(cnt == 0) {
                ele = x;
            }
            if(ele == x) {
                cnt += 1;
            }
            else {
                cnt -= 1;
            }
        }
        return ele;
    }
};