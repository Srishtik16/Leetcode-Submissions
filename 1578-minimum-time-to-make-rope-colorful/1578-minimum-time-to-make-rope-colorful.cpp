class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int mx = neededTime[0], sum = neededTime[0], ans = 0;
        for(int i = 1; i < n; i++) {
            if(colors[i] == colors[i - 1]) {
                sum += neededTime[i];
                mx = max(mx, neededTime[i]);
            }
            else {
                ans += sum - mx;
                mx = neededTime[i];
                sum = neededTime[i];
            }
        }
        ans += sum - mx;
        return ans;
    }
};