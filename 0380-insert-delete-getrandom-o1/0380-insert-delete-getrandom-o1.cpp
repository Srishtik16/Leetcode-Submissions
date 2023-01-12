#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class RandomizedSet {
public:
    vector<int> v;
    map<int, int> m;
    RandomizedSet() {
        v.clear();
        m.clear();
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end()) {
            return false;
        }
        v.push_back(val);
        m[val] = (int)size(v) - 1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) {
            return false;
        }
        int index = m[val];
        swap(v[index], v.back());
        swap(m[v[index]], m[v.back()]);
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int rnd = random(0, (int)size(v) - 1, int);
        return v[rnd];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */