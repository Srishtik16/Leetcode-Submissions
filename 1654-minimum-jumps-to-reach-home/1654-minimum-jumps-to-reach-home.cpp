class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // Note: node is uniquely represented by {val, direction}
        // Amazing point to consider while doing BFS
        queue<pair<int, int>> q;
        map<pair<int, int>, bool> vis;
        q.push({0, 1});
        vis[{0, 1}] = true;
        int d = 0;
        if(x == 0) {
            return 0;
        }
        auto isValid = [&](int node, int state) {
            return node >= 0 && node <= 1e4 && vis.find({node, state}) == vis.end() && find(forbidden.begin(), forbidden.end(), node) == forbidden.end();
        };
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int node = q.front().first;
                int prevMove = q.front().second;
                q.pop();
                if(node == x) {
                    return d + 1;
                }
                // 0 back, 1 forward
                if(prevMove == 0) {
                    int newIndex = node + a;
                    if(newIndex == x) {
                        return d + 1;
                    }
                    if(isValid(newIndex, 1)) {
                        vis[{newIndex, 1}] = true;
                        q.push({newIndex, 1}); // Forward jump to reach here
                    }
                }
                else {
                    if(isValid(node + a, 1)) {
                        if(node + a == x) {
                            return d + 1;
                        }
                        vis[{node + a, 1}] = true;
                        q.push({node + a, 1}); // Forward jump to reach here
                    }
                    if(isValid(node - b, 0)) {
                        if(node - b == x) {
                            return d + 1;
                        }
                        vis[{node - b, 0}] = true;
                        q.push({node - b, 0}); // Backward jump to reach here
                    }
                }
            }
            d++;
        }
        return -1;
    }
};