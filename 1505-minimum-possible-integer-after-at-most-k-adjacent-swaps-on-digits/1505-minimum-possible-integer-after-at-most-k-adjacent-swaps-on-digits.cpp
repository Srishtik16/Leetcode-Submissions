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
    string minInteger(string s, int k) {
        int n = s.size();
        fenwick_tree ft(n + 1);
        map<char, vector<int>> index;
        for(int i = n - 1; i >= 0; i--) {
            index[s[i]].push_back(i);
        }
        string ans = "";
        for(int i = 0; i < n; i++) {
            for(char d = '0'; d <= '9'; d++) {
                if(index[d].empty()) {
                    continue;
                }
                int movesToLeft = index[d].back() - ft.query(index[d].back());
                if(movesToLeft > k) {
                    continue;
                }
                k -= movesToLeft;
                ans += d;
                ft.update(index[d].back(), 1);
                index[d].pop_back();
                break;
            }
        }
        return ans;
    }
};