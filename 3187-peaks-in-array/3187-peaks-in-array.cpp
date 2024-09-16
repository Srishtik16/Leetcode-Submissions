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
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr = nums;
        auto isPeak = [&](int i) {
            if(i <= 0 || i >= n - 1) {
                return false;
            }
            return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
        };
        auto wasPeak = [&](int i) {
            if(i <= 0 || i >= n - 1) {
                return false;
            }
            return arr[i] > arr[i - 1] && arr[i] > arr[i + 1];
        };
        fenwick_tree ft(n);
        for(int i = 1; i < n - 1; i++) {
            if(isPeak(i)) {
                ft.update(i, 1);
            }
        }
        vector<int> ans;
        for(auto &q: queries) {
            int type = q[0];
            if(type == 1) {
                int l = q[1] + 1, r = q[2] - 1;
                if(l > r) {
                    ans.push_back(0);
                }
                else {
                    ans.push_back(ft.query(r) - ft.query(l - 1));
                }
            }
            else {
                int ind = q[1], val =  q[2];
                nums[ind] = val;
                for(int i = ind - 1; i < ind + 2; i++) {
                    if(isPeak(i) == wasPeak(i)) {
                        continue;
                    }
                    ft.update(i, wasPeak(i) ? -1 : 1);
                }
                arr[ind] = val;
            }
        }
        return ans;
    }
};