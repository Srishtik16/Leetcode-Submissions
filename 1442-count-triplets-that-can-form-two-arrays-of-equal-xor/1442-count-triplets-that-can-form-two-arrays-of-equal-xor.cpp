class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // find a subarray of 0 xor, all splits within it should be valid
        // we can find using a hashmap prefix xor approach
        map<int, int> m = {{0, 1}}, tm;
        int pref = 0;
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            pref ^= arr[i];
            ans += m[pref] * i - tm[pref];
            m[pref]++;
            tm[pref] += i + 1;
        }
        return ans;
    }
};