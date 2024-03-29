class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0, l = 0, r = (int)people.size() - 1;
        while(l < r) {
            if(people[l] + people[r] <= limit) {
                l++;
                r--;
                boats++;
            }
            else {
                r--;
                boats++;
            }
        }
        if(l == r) {
            boats++;
        }
        return boats;
    }
};