class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= sum;
        long long pref = 0;
        int student = 0;
        for(auto x: chalk) {
            pref += x;
            if(pref > k) {
                return student;
            }
            student++;
        }
        return -1;
    }
};