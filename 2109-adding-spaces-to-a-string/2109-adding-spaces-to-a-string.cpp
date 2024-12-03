class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.size();
        spaces.insert(spaces.begin(), 0);
        spaces.push_back(n);
        for(int i = 1; i < (int)spaces.size(); i++) {
            ans += s.substr(spaces[i - 1], spaces[i] - spaces[i - 1]);
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};