class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.size();
        if (len <= k) return false;
        int total = 1 << k;
        bool mmap[total];
        memset(mmap, 0, sizeof mmap);
        int allOnes = total-1;
        int cur = 0;
        for(int i=0;i<len;i++) {
            cur = ((cur << 1) & allOnes) | (s[i] == '1');
            if (i >= k-1) {
                mmap[cur] = true;
            }
        }
        for(int i=0;i<total;i++) {
            if (!mmap[i]) return false;
        }
        return true;
    }
};