class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> hash, hashp;
        int n = s.size();
        int m = p.size();
        int l = 0, r = m - 1;
        for(int i = 0; i < m - 1; i++) {
            hash[s[i]]++;
        }
        for(char c: p) {
            hashp[c]++;
        }
        vector<int> ans;
        while(r < n) {
            hash[s[r]]++;
            if(hash == hashp) {
                ans.push_back(l);
            }
            hash[s[l]]--;
            if(hash[s[l]] == 0) {
                hash.erase(s[l]);
            }
            l++;
            r++;
        }
        return ans;
    }
};