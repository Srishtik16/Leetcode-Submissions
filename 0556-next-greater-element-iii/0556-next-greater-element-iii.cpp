class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(next_permutation(s.begin(), s.end())) {
            long long ans = stoll(s) > INT_MAX ? -1 : stoll(s);
            return ans;
        }
        return -1;
    }
};