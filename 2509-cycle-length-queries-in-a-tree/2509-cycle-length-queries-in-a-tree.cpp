class Solution {
public:
    int getDepth(int node) {
        int depth = 0;
        while(node > 1) {
            node /= 2;
            depth++;
        }
        return depth;
    }
    int getLCA(int u, int v) {
        int du = getDepth(u);
        int dv = getDepth(v);
        if(du < dv) {
            swap(u, v);
            swap(du, dv);
        }
        while(du > dv) {
            u /= 2;
            du = getDepth(u);
        }
        while(u != v) {
            u /= 2;
            v /= 2;
        }
        return u;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto x: queries) {
            int u = x[0], v = x[1];
            int du = getDepth(u);
            int dv = getDepth(v);
            int dlca = getDepth(getLCA(u, v));
            ans.push_back(du + dv - 2 * dlca + 1);
        }
        return ans;
    }
};