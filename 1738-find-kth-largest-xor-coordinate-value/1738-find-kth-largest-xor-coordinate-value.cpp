class fenwick_tree{
private:
    vector<vector<long long>> BIT;
public:
    fenwick_tree() {
        BIT.resize(1, vector<long long>(1, 0));
    }
    fenwick_tree(int n, int m){
        BIT.resize(n + 1, vector<long long>(m + 1, 0));
    }
    long long query(int x, int y){
        long long res = 0;
        int i = x;
        while(i >= 0){
            int j = y;
            while(j >= 0) {
                res ^= BIT[i][j];
                j = (j & (j + 1)) - 1;
            }
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    void update(int x, int y, int val){
        int i = x;
        while(i < BIT.size()){
            int j = y;
            while(j < BIT[0].size()) {
                BIT[i][j] ^= val;
                j = (j | (j + 1));
            }
            i = (i | (i + 1));
        }
    }
};
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        fenwick_tree ft(n + 1, m + 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ft.update(i, j, matrix[i][j]);
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pq.size() < k) {
                    pq.push(ft.query(i, j));
                }
                else if(pq.top() < ft.query(i, j)) {
                    pq.pop();
                    pq.push(ft.query(i, j));
                }
            }
        }
        return pq.top();
    }
};