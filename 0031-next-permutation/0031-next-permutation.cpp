class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        bool isSorted = true;
        for(int i = 0; i < n - 1; i++) {
            isSorted &= a[i] >= a[i + 1];
        }
        if(isSorted) {
            reverse(a.begin(), a.end());
            return;
        }
        int indexWhereDecrease = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(a[i] < a[i + 1]) {
                indexWhereDecrease = i;
                break;
            }
        }
        int indexToBeSwapped = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(a[indexWhereDecrease] < a[i]) {
                indexToBeSwapped = i;
                break;
            }
        }
        if(indexToBeSwapped < indexWhereDecrease) {
            reverse(a.begin(), a.end());
            return;
        }
        swap(a[indexWhereDecrease], a[indexToBeSwapped]);
        int j = n - 1;
        for(int i = indexWhereDecrease + 1; i < n; i++) {
            if(i >= j) {
                break;
            }
            swap(a[i], a[j]);
            j--;
        }
    }
};