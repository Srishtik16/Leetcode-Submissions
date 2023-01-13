class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        int i = 0, j = 1;
        vector<string> ans;
        while(i < m) {
            if(target[i] == j) {
                ans.push_back("Push");
                i++;
            }
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            j++;
        }
        return ans;
    }
};