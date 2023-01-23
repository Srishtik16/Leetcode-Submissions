class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for(int i = n; i >= 1; i--) {
            int index = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j] == i) {
                    index = j;
                    break;
                }
            }
            ans.push_back(index + 1);
            reverse(arr.begin(), arr.begin() + index + 1);
            ans.push_back(i);
            reverse(arr.begin(), arr.begin() + i);
        }
        assert(is_sorted(arr.begin(), arr.end()));
        return ans;
    }
};