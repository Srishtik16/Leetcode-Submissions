class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        int j = 0, res = 0, cover = 0;
        for(int i = 0; res < carpetLen && i < n;) {
            if(tiles[j][0] + carpetLen > tiles[i][1]) {
                cover += tiles[i][1] - tiles[i][0] + 1;
                res = max(res, cover);
                i++;
            }
            else {
                int partial = max(0, tiles[j][0] + carpetLen - tiles[i][0]);
                res = max(res, cover + partial);
                cover -= tiles[j][1] - tiles[j][0] + 1;
                j++;
            }
        }
        return res;
    }
};