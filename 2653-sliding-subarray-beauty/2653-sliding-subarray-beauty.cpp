#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        ordered_set st;
        for(int i = 0; i < k; i++) {
            st.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*st.find_by_order(x - 1));
        if(ans.back() > 0) {
            ans.back() = 0;
        }
        for(int i = k; i < n; i++) {
            st.insert(nums[i]);
            st.erase(st.find_by_order(st.order_of_key(nums[i - k])));
            ans.push_back(*st.find_by_order(x - 1));
            if(ans.back() > 0) {
                ans.back() = 0;
            }
        }
        return ans;
    }
};