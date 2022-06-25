// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        auto get = [&]() {
            int r1 = rand7();
            int r2 = rand7();
            return (r1 - 1) * 7 + r2;
        };
        do {
            int rnd = get();
            if(rnd <= 40) {
                return rnd % 10 + 1;
            }
        }while(true);
    }
};