class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cost = 0;
        int cap = capacity;
        for(int i = 0; i < n; i++) {
            cost += 1;
            if(plants[i] > cap) {
                cost += 2 * abs(i - 1 - -1);
                cap = capacity;
                cap -= plants[i];
            }
            else {
                cap -= plants[i];
            }
        }
        return cost;
    }
};