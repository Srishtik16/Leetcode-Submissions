class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int curr = 0, i = 0, n = skills.size();
        for(int j = 1; j < n; j++) {
            if(skills[i] < skills[j]) {
                curr = 0;
                i = j;
            }
            if(++curr == k) {
               break;
            }
        }
        return i;
    }
};