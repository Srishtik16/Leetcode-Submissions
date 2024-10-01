class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int cnt = 1, andScore = (1LL << 21) - 1;
        int last = nums.back();
        nums.pop_back();
        int index = -1, i = 0;
        for(auto x: nums) {
            andScore &= x;
            if(andScore == 0) {
                index = i;
                cnt++;
                andScore = (1LL << 21) - 1;
            }
            i++;
        }
        nums.push_back(last);
        int lastAndScore = (1LL << 21) - 1;
        for(int i = index + 1; i < (int)nums.size(); i++) {
            lastAndScore &= nums[i];
        }
        if(index != -1 && lastAndScore != 0) {
            cnt--;
        }
        return cnt;
    }
};