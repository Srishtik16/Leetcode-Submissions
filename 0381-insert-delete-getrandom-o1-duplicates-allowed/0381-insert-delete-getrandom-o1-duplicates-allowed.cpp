#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class RandomizedCollection {
public:
    vector<int> v;
    map<int, unordered_set<int>> m;
    RandomizedCollection() {
        v.clear();
        m.clear();
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end()) {
            v.push_back(val);
            m[val].insert((int)size(v) - 1);
            return false;
        }
        v.push_back(val);
        m[val].insert((int)size(v) - 1);
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) {
            return false;
        }
        auto index = *m[val].begin();
        m[val].erase(m[val].begin());
        v[index] = v.back();
        m[v.back()].insert(index);
        m[v.back()].erase((int)size(v) - 1);
        v.pop_back();
        if(m[val].empty()) {
            m.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int rnd = random(0, (int)size(v) - 1, int);
        return v[rnd];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */