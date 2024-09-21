class Solution {
public:
    long long wonderfulSubstrings(string word) {
        // prefix mask approach
        // if a substring has xor = 2 ^ i then good
        int n = word.size();
        long long pref = 0, ans = 0;
        map<int, int> masks;
        masks[0]++;
        for(char c: word) {
            pref ^= (1 << (c - 'a'));
            ans += masks[pref];
            masks[pref]++;
            for(int i = 0; i < 10; i++) {
                int val = pref ^ (1 << i);
                if(masks.find(val) != masks.end()) {
                    ans += masks[val];
                }
            }
        }
        return ans;
    }
};