class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> found;
    RandomizedSet() {
        ;
    }
    
    bool insert(int val) {
        if(found.find(val) == found.end()) {
            nums.push_back(val);
            found[val] = nums.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(found.find(val) == found.end()) {
            return false;
        }
        int last = nums.back();
        found[last] = found[val];
        nums[found[val]] = last;
        nums.pop_back();
        found.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % (nums.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */