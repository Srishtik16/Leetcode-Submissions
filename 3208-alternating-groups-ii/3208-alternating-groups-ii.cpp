class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i = 0; i < n; i++) {
            colors.push_back(colors[i]);
        }
        int islands = 1, ans = 0;
        for(int i = 1; i < n + k - 1; i++) {
            if(colors[i] != colors[i - 1]) {
                islands++;
            }
            else {
                ans += max(0, islands - k + 1);
                islands = 1;
            }
        }
        ans += max(0, islands - k + 1);
        return ans;
    }
};