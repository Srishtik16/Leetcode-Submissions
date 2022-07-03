class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int MaxN = 1e5 + 5;
        vector<int> hash(MaxN, 0), ans;
        for(auto x: changed) {
            hash[x]++;
        }
        for(int i = 0; i <= 50000; i++) {
            if(hash[i]) {
                if(--hash[i] < 0 || --hash[i * 2] < 0) {
                    return vector<int>();
                }
                ans.push_back(i);
                i--;
            }
        }
        int sum = 0;
        for(int i = 0; i < MaxN; i++) {
            sum += hash[i];
        }
        if(sum > 0) {
            return vector<int>();
        }
        else {
            return ans;
        }
    }
};