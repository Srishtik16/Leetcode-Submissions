class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int, int> m;
        for(auto x: arr) {
            m[x]++;
        }
        int cnt = 0;
        for(int i = 1;; i++) {
            if(m[i] == 0) {
                cnt++;
            }
            if(cnt == k) {
                return i;
            }
        }
        return -1;
    }
};