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
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        fenwick_tree ft(n);
        int chunks = 0;
        for(int i = 0; i < n; i++) {
            ft.update(arr[i], 1);
            if(ft.query(i) == i + 1) {
                chunks++;
            }
        }
        return chunks;   
    }
};