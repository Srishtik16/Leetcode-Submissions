class RLEIterator {
public:
    int index;
    vector<int> e;
    RLEIterator(vector<int>& encoding) {
        index = 0;
        e = encoding;
    }
    
    int next(int n) {
        while(index < e.size() && n >= 0) {
            int mn = min(e[index], n);
            n -= mn;
            e[index] -= mn;
            if(e[index] == 0 && n == 0) {
                int i = index;
                index += 2;
                return e[i + 1];
            }
            else if(e[index] == 0) {
                index += 2;
            }
            else if(n == 0) {
                return e[index + 1];
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */