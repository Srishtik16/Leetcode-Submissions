class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int index = -1;
        vector<int> bestLeft(n, INT_MAX), bestRight(n, INT_MAX);
        for(int i = 0; i < n; i++) {
            if(seats[i] == 1) {
                index = i;
                bestLeft[i] = 0;
            }
            else {
                bestLeft[i] = index == -1 ? INT_MAX : abs(index - i);
            }
        }
        index = -1;
        for(int i = n - 1; i >= 0; i--) {
            if(seats[i] == 1) {
                index = i;
                bestRight[i] = 0;
            }
            else {
                bestRight[i] = index == -1 ? INT_MAX : abs(index - i);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, min(bestLeft[i], bestRight[i]));
        }
        return ans;
    }
};