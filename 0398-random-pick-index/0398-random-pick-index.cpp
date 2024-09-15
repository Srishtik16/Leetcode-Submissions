#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    map<int, vector<int>> index;
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            index[nums[i]].push_back(i);
        }
    }
    int pick(int target) {
        int n = index[target].size();
        int r = random(0, n - 1, int);
        return index[target][r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */