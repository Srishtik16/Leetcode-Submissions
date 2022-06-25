class Solution {
public:
    vector<int> a;
    vector<int> copy;
    Solution(vector<int>& nums) {
        a = nums;
        copy = nums;
    }
    
    vector<int> reset() {
        a = copy;
        return a;
    }
    
    vector<int> shuffle() {
        int n = a.size();
        // Fischer Yales Algorithm 
        // for random shuffle an array
        for(int i = n - 1; i >= 0; i--) {
            int ind = rand() % (i + 1);
            swap(a[i], a[ind]);
        }
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */