class fenwick_tree{
private:
    vector<long long> BIT;
public:
    fenwick_tree(int n){
        BIT.resize(n + 1, 0);
    }
    long long query(int i){
        long long res = 0;
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
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        fenwick_tree ft0(n), ft1(n);
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                ft0.update(i, 1);
            }
            else {
                ft1.update(i, 1);
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, int(ft1.query(i) + ft0.query(n) - ft0.query(i)));
        }
        ans = min(ans, int(ft0.query(n)));
        return ans;
    }
};