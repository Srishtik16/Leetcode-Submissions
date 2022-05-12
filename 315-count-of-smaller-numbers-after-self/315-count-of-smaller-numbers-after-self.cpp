const int MaxN = 2e4 + 5;
class fenwick_tree{
private:
    vector<int> BIT;
public:
    fenwick_tree(int n){
        BIT.resize(n+1,0);
    }
    int query(int i){
        int res=0;
        while(i>=0){
            res+=BIT[i];
            i = (i&(i+1))-1;
        }
        return res;
    }
    void update(int i,int val){
        while(i<BIT.size()){
            BIT[i]+=val;
            i = (i|(i+1));
        }
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        map<int, int> m;
        vector<int> a = nums;
        sort(a.begin(), a.end());
        int ptr = 0;
        for(auto x: a) {
            if(m.find(x) == m.end()) {
                m[x] = ptr;
                ptr++;
            }
        }
        fenwick_tree ft(MaxN);
        vector<int> ans((int)nums.size());
        for(int i = (int)nums.size() - 1; i >= 0; i--) {
            ans[i] = ft.query(m[nums[i]] - 1);
            ft.update(m[nums[i]], 1);
        }
        return ans;
    }
};