class Node {
public:
    int majority, delta;
};
class SegmentTree {
public:
    vector<Node> st;
    Node merge(Node x, Node y) {
        Node merged;
        if(x.majority == y.majority) {
            merged.majority = x.majority;
            merged.delta = x.delta + y.delta;
        }
        else {
            merged.majority = x.delta > y.delta ? x.majority : y.majority;
            merged.delta = max(x.delta, y.delta) - min(x.delta, y.delta);
        }
        return merged;
    }
    void build(int node, int start, int end, vector<int> &a) {
        if(start == end) {
            st[node].majority = a[start];
            st[node].delta = 1;
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, a);
        build(2 * node + 2, mid + 1, end, a);
        st[node] = merge(st[2 * node + 1], st[2 * node + 2]);
    }
    Node query(int node, int start, int end, int l, int r) {
        if(l <= start && r >= end) {
            return st[node];
        }
        if(l > end || r < start) {
            Node identity;
            identity.majority = -1;
            identity.delta = 0;
            return identity;
        }
        int mid = (start + end) / 2;
        Node q = merge(query(2 * node + 1, start, mid, l, r), query(2 * node + 2, mid + 1, end, l, r));
        return q;
    }
};
class MajorityChecker {
public:
    map<int, vector<int>> indexes;
    SegmentTree st;
    int n;
    MajorityChecker(vector<int>& arr) {
        n = arr.size();
        st.st.resize(4 * n);
        for(int i = 0; i < n; i++) {
            indexes[arr[i]].push_back(i);
        }
        st.build(0, 0, n - 1, arr);
    }
    
    int query(int left, int right, int threshold) {
        int q = st.query(0, 0, n - 1, left, right).majority;
        auto countFreq = [&] (int val, int l, int r) {
            int freq = upper_bound(indexes[val].begin(), indexes[val].end(), r) - lower_bound(indexes[val].begin(), indexes[val].end(), l);
            return freq;
        };
        if(countFreq(q, left, right) >= threshold) {
            return q;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */