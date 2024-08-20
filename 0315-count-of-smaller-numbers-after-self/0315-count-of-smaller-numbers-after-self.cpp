class fenwick_tree{
private:
    vector<int> BIT;
public:
    fenwick_tree(int n){
        BIT.resize(n + 1, 0);
    }
    int query(int i){
        int res = 0;
        while(i >= 0){
            res += BIT[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    void update(int i, int val){
        while(i < BIT.size()){
            BIT[i] += val;
            i = (i | (i + 1));
        }
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int MaxN = 2e4 + 5;
        fenwick_tree ft(MaxN);
        for(auto &x: nums) {
            x += 1e4 + 1;
        }
        int n = nums.size();
        vector<int> ans;
        for(int i = n - 1; i >= 0; i--) {
            ans.push_back(ft.query(nums[i] - 1));
            ft.update(nums[i], 1);
        }
        reverse(ans.begin(), ans.end());
        assert(ans.back() == 0);
        return ans;
    }
};