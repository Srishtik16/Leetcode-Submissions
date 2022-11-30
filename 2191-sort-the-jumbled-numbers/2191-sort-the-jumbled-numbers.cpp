class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto getMapping = [&](int n) {
            string s = to_string(n);
            string t = "";
            for(char c: s) {
                string st = "";
                st += c;
                int index = stoi(st);
                int mappedNum = mapping[index];
                t += to_string(mappedNum);
            }
            return stoi(t);
        };
        vector<array<int, 3>> mapped;
        int index = 0;
        for(auto x: nums) {
            mapped.push_back({getMapping(x), index, x});
            index++;
        }
        sort(mapped.begin(), mapped.end());
        vector<int> ans;
        for(auto x: mapped) {
            ans.push_back(x[2]);
        }
        return ans;
    }
};