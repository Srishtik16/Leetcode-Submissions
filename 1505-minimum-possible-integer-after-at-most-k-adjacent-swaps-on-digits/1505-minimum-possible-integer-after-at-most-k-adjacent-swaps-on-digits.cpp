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
    string minInteger(string s, int k) {
        int n = s.size();
        fenwick_tree ft(n + 1);
        map<char, vector<int>> ind;
        for(int i = n - 1; i >= 0; i--) {
            ind[s[i]].push_back(i);
        }
        string ans = "";
        for(int i = 0; i < n; i++) {
            for(char d = '0'; d <= '9'; d++) {
                if(ind[d].empty()) {
                    continue;
                }
                int nearestRight = ind[d].back() - ft.query(ind[d].back());
                if(nearestRight > k) {
                    continue;
                }
                k -= nearestRight;
                ans += d;
                ft.update(ind[d].back(), 1);
                ind[d].pop_back();
                break;
            }
        }
        return ans;
    }
};