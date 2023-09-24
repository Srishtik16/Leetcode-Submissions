class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> flows(105, vector<double>(105, 0.0));
        flows[0][0] = poured;
        for(int i = 0; i <= query_row; i++) {
            for(int j = 0; j <= i; j++) {
                double flowedOver = max(0.0, (flows[i][j] - 1.0) / 2.0);
                flows[i + 1][j] += flowedOver;
                flows[i + 1][j + 1] += flowedOver;
            }
        }
        return min(1.0, flows[query_row][query_glass]);
    }
};