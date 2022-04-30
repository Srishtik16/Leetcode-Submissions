class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1 = -1, m2 = -1, c1 = 0, c2 = 0;
        for(auto x: nums) {
            if(m1 == x) {
                c1++;
            }
            else if(m2 == x) {
                c2++;
            }
            else if(c1 == 0) {
                m1 = x;
                c1 = 1;
            }
            else if(c2 == 0) {
                m2 = x;
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }
        c1 = 0, c2 = 0;
        for(auto x: nums) {
            c1 += x == m1;
            c2 += x == m2;
        }
        vector<int> ans;
        if(c1 > (int)nums.size() / 3) {
            ans.push_back(m1);
        }
        if(c2 > (int)nums.size() / 3) {
            ans.push_back(m2);
        }
        for(auto x: ans) {
            cout << x << " ";
        }
        cout << endl;
        if(!ans.empty() && ans.front() == ans.back() && ans.size() == 2) {
            ans.pop_back();
        }
        return ans;
    }
};