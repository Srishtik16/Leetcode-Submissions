class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int days) {
        int n = cells.size();
        days %= 14;
        if(days == 0) {
            days = 14;
        }
        while(days--) {
            vector<int> a = cells;
            for(int i = 1; i < n - 1; i++) {
                if(cells[i - 1] == cells[i + 1]) {
                    a[i] = 1;
                }
                else {
                    a[i] = 0;
                }
            }
            a[0] = 0;
            a[n - 1] = 0;
            cells = a;
        }
        return cells;
    }
};