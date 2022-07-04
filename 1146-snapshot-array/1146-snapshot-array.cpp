class SnapshotArray {
public:
    unordered_map<int, map<int, int>> snaps;
    int id;
    SnapshotArray(int length) {
        id = 0;
    }
    
    void set(int index, int val) {
        snaps[index][id] = val;
    }
    
    int snap() {
        id++;
        return id - 1;
    }
    
    int get(int index, int snap_id) {
        auto it = snaps[index].upper_bound(snap_id);
        if(it == snaps[index].begin()) {
            return 0;
        }
        else {
            return prev(it) -> second;
        }
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */