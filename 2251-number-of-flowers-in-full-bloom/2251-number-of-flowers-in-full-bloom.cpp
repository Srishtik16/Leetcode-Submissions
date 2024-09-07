class fenwick_tree{
private:
    unordered_map<int, int> BIT;
public:
    fenwick_tree(){
        ;
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
        while(i < (int)1e9 + 5){
            BIT[i] += val;
            i = (i | (i + 1));
        }
    }
};
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        fenwick_tree ft;
        for(auto x: flowers) {
            ft.update(x[0], 1);
            ft.update(x[1] + 1, -1);
        }
        for(auto &x: people) {
             x = ft.query(x);
        }
        return people;
    }
};