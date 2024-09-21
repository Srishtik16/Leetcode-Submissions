class Node {
public: 
    int distance;
    int speed;
    int position;
    int direction;
    Node(int dis, int spd, int pos, int dir) {
        distance = dis;
        speed = spd;
        position = pos;
        direction = dir;
    }
};
class Solution {
public:
    int racecar(int target) {
        int maxDistance = 0;
        int maxSpeed = 0;
        while(maxDistance < target) {
            maxDistance += (1 << maxSpeed);
            maxSpeed++;
        }
        bool vis[maxDistance + 1][maxSpeed + 1][2];
        memset(vis, false, sizeof(vis));
        Node node(0, 0, 0, 1);
        vis[0][0][0] = true;
        queue<Node> q;
        q.push(node);
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                Node currNode = q.front();
                q.pop();
                if(currNode.position == target) {
                    return currNode.distance;
                }
                Node adjNode = currNode;
                adjNode.position += (1 << adjNode.speed) * adjNode.direction;
                adjNode.speed++;
                adjNode.distance++;
                if(adjNode.position < 0 || adjNode.position > maxDistance) {
                    goto end;
                }
                if(!vis[adjNode.position][adjNode.speed][(adjNode.direction + 2) / 2]) {
                    vis[adjNode.position][adjNode.speed][(adjNode.direction + 2) / 2] = true;
                    q.push(adjNode);
                }
                end:
                adjNode = currNode;
                adjNode.direction *= -1;
                adjNode.speed = 0;
                adjNode.distance++;
                if(!vis[adjNode.position][adjNode.speed][(adjNode.direction + 2) / 2]) {
                    vis[adjNode.position][adjNode.speed][(adjNode.direction + 2) / 2] = true;
                    q.push(adjNode);
                }
            }
        }
        return -1;
    }
};