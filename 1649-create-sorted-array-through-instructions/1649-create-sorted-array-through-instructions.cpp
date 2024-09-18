class fenwick_tree {
public: 
    vector<int> BIT;
    fenwick_tree(int n) {
        BIT.assign(n + 1, 0);
    }
    int query(int i) {
        int res = 0;
        while(i >= 0) {
            res += BIT[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    void update(int i, int val) {
        while(i < BIT.size()) {
            BIT[i] += val;
            i = i | (i + 1);
        }
    }
};
class Solution {
public:
    const int MaxN = 1e5 + 5;
    const int MOD = 1e9 + 7;
    int createSortedArray(vector<int>& instructions) {
        fenwick_tree ft(MaxN);
        long long cost = 0;
        for(int i = 0; i < instructions.size(); i++) {
            int less = ft.query(instructions[i] - 1);
            int more = i - ft.query(instructions[i]);
            cost += min(less, more);
            cost %= MOD;
            ft.update(instructions[i], 1);
        }
        return cost;
    }
};