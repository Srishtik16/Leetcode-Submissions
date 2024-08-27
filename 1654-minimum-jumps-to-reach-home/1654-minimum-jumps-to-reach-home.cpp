class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int steps = 8e3;
        queue<pair<int, int>> q;
        map<int, bool> vis;
        q.push({0, -1});
        vis[0] = true;
        if(x == 0) {
            return 0;
        }
        int d = 0;
        auto isValid = [&](int node) {
            return node >= 0 && node <= 1e4 && vis.find(node) == vis.end() && find(forbidden.begin(), forbidden.end(), node) == forbidden.end();
        };
        while(!q.empty()) {
            int qs = q.size();
            if(steps == 0) {
                break;
            }
            while(qs--) {
                int node = q.front().first;
                int prevMove = q.front().second;
                if(true) {
                    vis[node] = true;
                }
                //cout << node << " " << prevMove << endl;
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
                    if(isValid(newIndex)) {
                        vis[newIndex] = true;
                        q.push({newIndex, 1}); // Forward jump to reach here
                    }
                }
                else {
                    if(isValid(node + a)) {
                        if(node + a == x) {
                            return d + 1;
                        }
                        vis[node + a] = true;
                        q.push({node + a, 1}); // Forward jump to reach here
                    }
                    if(isValid(node - b)) {
                        if(node - b == x) {
                            return d + 1;
                        }
                        //vis[node - b] = true;
                        q.push({node - b, 0}); // Backward jump to reach here
                    }
                }
            }
            d++;
            steps--;
        }
        return -1;
    }
};