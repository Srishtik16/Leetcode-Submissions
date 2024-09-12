class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                string s1 = to_string(nums[i]);
                string s2 = to_string(nums[j]);
                if(s1 == s2) {
                    ans++;
                    continue;
                }
                for(int k = 0; k < s1.size(); k++) {
                    bool ok = false;
                    for(int l = k + 1; l < s1.size(); l++) {
                        swap(s1[k], s1[l]);
                        if(stoll(s1) == stoll(s2)) {
                            ok = true;
                            ans++;
                        }
                        swap(s1[k], s1[l]);
                        if(ok) {
                            goto here;
                        }
                    }
                }
                for(int k = 0; k < s2.size(); k++) {
                    bool ok = false;
                    for(int l = k + 1; l < s2.size(); l++) {
                        swap(s2[k], s2[l]);
                        if(stoll(s1) == stoll(s2)) {
                            ok = true;
                            ans++;
                        }
                        swap(s2[k], s2[l]);
                        if(ok) {
                            goto here;
                        }
                    }
                }
                here:
                ;
            }
        }
        return ans;
    }
};