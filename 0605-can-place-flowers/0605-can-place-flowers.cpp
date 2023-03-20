class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = count(flowerbed.begin(), flowerbed.end(), 1);
        if(flowerbed.size() == 1) {
            if(flowerbed.back() == 1) {
                return n == 0;
            }
            else {
                return n <= 1;
            }
        }
        for(int i = 0; i < (int)flowerbed.size(); i++) {
            if(i == 0) {
                if(flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                }
            }
            else if(i == (int)flowerbed.size() - 1) {
                if(flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
                    flowerbed[i - 1] = 1;
                }
            }
            else {
                if(flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                }
            }
        }
        int cnt1 = count(flowerbed.begin(), flowerbed.end(), 1);
        return n <= abs(cnt - cnt1);
    }
};