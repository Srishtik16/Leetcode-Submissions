class Solution {
public:
    map<int, bool> positions;
    map<pair<int, int>, int> dp;
    bool recurse(int index, int destination, int currStep) {
        if(index == destination) {
            return true;
        }
        if(index > destination) {
            return false;
        }
        if(!positions[index]) {
            return false;
        }
        if(index < 0) {
            return false;
        }
        if(dp.find({index, currStep}) != dp.end()) {
            return dp[{index, currStep}];
        }
        return dp[{index, currStep}] = (currStep > 0 ? recurse(index + currStep, destination, currStep) : false) || (currStep > 1 ? recurse(index + currStep - 1, destination, currStep - 1) : false) || (currStep > -1 ? recurse(index + currStep + 1, destination, currStep + 1) : false);
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        positions.clear();
        for(auto x: stones) {
            positions[x] = true;
        }
        return recurse(0, stones.back(), 0);
    }
};