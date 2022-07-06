class Node {
public:
    int position, direction, speed, distance;
    Node(int _pos, int _dir, int _speed, int _dist) {
        position = _pos;
        direction = _dir;
        speed = _speed;
        distance = _dist;
    }  
};
class Solution {
public:
    int racecar(int target) {
        int maxSpeed = 0, maxDistance = 0;
        while(maxDistance < target) {
            maxDistance += (1LL << maxSpeed);
            maxSpeed++;
        }
        int dp[maxDistance + 1][maxSpeed + 1][2];
        bool vis[maxDistance + 1][maxSpeed + 1][2];
        memset(dp, -1, sizeof(dp));
        memset(vis, false, sizeof(vis));
        queue<Node> q;
        q.push(Node(0, 1, 0, 0));
        dp[0][0][0] = 0;
        vis[0][0][0] = 1;
        while(!q.empty()) {
            Node currNode = q.front();
            q.pop();
            if(currNode.position == target) {
                return currNode.distance;
            }
            Node adjNode = currNode;
            adjNode.direction *= -1;
            adjNode.speed = 0;
            adjNode.distance++;
            if(!vis[adjNode.position][adjNode.speed][(adjNode.direction + 2) / 2]) {
                vis[adjNode.position][adjNode.speed][(adjNode.direction + 2) / 2] = true;
                dp[adjNode.position][adjNode.speed][(adjNode.direction + 2) / 2] = adjNode.distance;
                q.push(adjNode);
            }
            adjNode = currNode;
            adjNode.position += (1LL << adjNode.speed) * adjNode.direction;
            adjNode.speed++;
            adjNode.distance++;
            if(adjNode.position < 0 || adjNode.position > maxDistance) {
                continue;
            }
            if(!vis[adjNode.position][adjNode.speed][(adjNode.direction + 2) / 2]) {
                vis[adjNode.position][adjNode.speed][(adjNode.direction + 2) / 2] = true;
                dp[adjNode.position][adjNode.speed][(adjNode.direction + 2) / 2] = adjNode.distance;
                q.push(adjNode);
            }
        }
        return -1;
    }
};