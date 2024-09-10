class DetectSquares {
public:
    map<pair<int, int>, int> counts;
    vector<pair<int, int>> points;
    DetectSquares() {
        counts.clear();
        points.clear();
    }
    
    void add(vector<int> point) {
        counts[{point[0], point[1]}]++;
        points.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1], ans = 0;
        for(auto x: points) {
            int x3 = x.first, y3 = x.second;
            if(x3 == x1 || y3 == y1 || abs(x3 - x1) == 0 || abs(x1 - x3) != abs(y1 - y3)) {
                continue;
            }
            ans += counts[{x1, y3}] * counts[{x3, y1}];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */