class Node {
public:
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> mat;
    Node(vector<vector<int>> &m) {
        mat = m;
    }
    bool isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < mat.size() && j < mat[0].size();
    }
    void flip(int i, int j) {
        mat[i][j] ^= 1;
        for(auto dir: dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if(isValid(ni, nj)) {
                mat[ni][nj] ^= 1;
            }
        }
    }
    vector<vector<vector<int>>> getNeighbours() {
        vector<vector<vector<int>>> neighbours;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                flip(i, j);
                neighbours.push_back(mat);
                flip(i, j);
            }
        }
        return neighbours;
    }
};
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        Node source(mat);
        queue<Node> q;
        q.push(source);
        int steps = 0;
        map<vector<vector<int>>, bool> vis;
        vis[source.mat] = true;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                Node node = q.front();
                q.pop();
                if(node.mat == vector<vector<int>>(n, vector<int>(m))) {
                    return steps;
                }
                auto child = node.getNeighbours();
                for(auto x: child) {
                    if(!vis[x]) {
                        Node c(x);
                        q.push(c);
                        vis[x] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};