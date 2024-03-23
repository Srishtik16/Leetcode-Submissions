class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string even1 = "", odd1 = "", even2 = "", odd2 = "";
        bool parity = true;
        for(char c: s1) {
            if(parity) {
                odd1 += c;
            }
            else {
                even1 += c;
            }
            parity ^= 1;
        }
        parity = true;
        for(char c: s2) {
            if(parity) {
                odd2 += c;
            }
            else {
                even2 += c;
            }
            parity ^= 1;
        }
        sort(even1.begin(), even1.end());
        sort(odd1.begin(), odd1.end());
        sort(even2.begin(), even2.end());
        sort(odd2.begin(), odd2.end());
        return even1 == even2 && odd1 == odd2;
    }
};