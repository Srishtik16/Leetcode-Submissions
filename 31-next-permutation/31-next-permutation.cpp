class Solution {
public:
    void nextPermutation(vector<int>& a) {
        reverse(a.begin(), a.end());
        if(is_sorted(a.begin(), a.end())) {
            return;
        }
        reverse(a.begin(), a.end());
        int n = a.size();
        int ind1 = 0;
        for(int i = n - 1; i >= 1; i--) {
            if(a[i] > a[i - 1]) {
                ind1 = i - 1;
                break;
            }
        }
        int ind2 = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(a[ind1] < a[i]) {
                ind2 = i;
                break;
            }
        }
        if(ind2 < ind1) {
            reverse(a.begin(), a.end());
            return;
        }
        swap(a[ind1], a[ind2]);
        reverse(a.begin() + ind1 + 1, a.end());
        return;
    }
};