class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int Xor = 0;
        int n = nums.size();
        for(int i = 1; i <= n; i++) {
            Xor ^= i;
            Xor ^= nums[i - 1];
        }
        int bit = 0;
        for(int i = 0; i <= 30; i++) {
            if((1 << i) & Xor) {
                bit = i;
                break;
            }
        }
        int f = 0, s = 0;
        for(auto x: nums) {
            if(x & (1 << bit)) {
                f ^= x;
            }
            else {
                s ^= x;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i & (1 << bit)) {
                f ^= i;
            }
            else {
                s ^= i;
            }
        }
        int cnt = 0;
        for(auto x: nums) {
            if(f == x) {
                cnt++;
            }
        }
        if(cnt == 0) {
            swap(f, s);
        }
        return vector<int> {f, s};
    }
};