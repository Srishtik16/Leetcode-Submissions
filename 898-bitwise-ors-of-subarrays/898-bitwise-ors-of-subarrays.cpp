class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        // prev -> pref[i - 1]
        // curr -> pref[i]
        set<int> prev, ans;
        for(int i = 0; i < n; i++) {
            set<int> curr;
            curr.insert(A[i]);
            ans.insert(A[i]);
            for(auto x: prev) {
                curr.insert(x | A[i]);
                ans.insert(x | A[i]);
            }
            prev = curr;
        }
        return ans.size();
    }
};

// I want to count number of distinct values for subarrays ending at i
// pref[i - 1] = OR of 1st i - 1 elements
// I am standing at i
// pref[i - 1] | a[i]
// pref[i] --> Atmost 30 different values
// I want to compute ending at i
// Answer = sum of all answer at i
// If I am i
// a[i], a[i] | a[i - 1], a[i]